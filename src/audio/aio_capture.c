/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: aio_capture.c          */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "macros.h"
#include "magnetar.h"
#include "aio.h"
#include "opus/opus_defines.h"
#include "settings.h"
#include "nw_interface.h"

#include <miniaudio/miniaudio.h>
#include <opus/opus.h>
#include <malloc.h>
#include <stdio.h>

ma_device capture_device;
ma_device_config capture_config;
OpusEncoder* opus_encoder;

void capture_data_callback(ma_device* pDevice, void* pOutput, const void* pInput, uint32_t frameCount)
{
	//data callback
  DEBUG_PRINTF("%d\n", *((int*)pInput));
  NW_PACKET* audio_input_packet = (NW_PACKET*)malloc(1921);
  OpusEncoder* encoder = (OpusEncoder*)pDevice->pUserData;
  int32_t audio_input_packet_size;
  int32_t err;
  audio_input_packet_size = opus_encode(encoder, (const int16_t*)pInput, frameCount, audio_input_packet->data.audio.pcm, 480);
  audio_input_packet->type = PACKETTYPE_AUDIO;

  send_nw(audio_input_packet, audio_input_packet_size+1);
}

int32_t init_miniaudio_capture()
{
	capture_config = ma_device_config_init(ma_device_type_capture);

	capture_config.capture.format = ma_format_s32;
	capture_config.capture.channels = 2;
	capture_config.wasapi.noAutoConvertSRC = MA_TRUE;
	capture_config.dataCallback = capture_data_callback;
  
  int32_t opus_encoder_err;
  opus_encoder = opus_encoder_create(SAMPLE_RATE, CHANNELS, OPUS_APPLICATION_AUDIO, &opus_encoder_err);
  if (opus_encoder_err < 0)
  {
    error_type = FAILED_TO_CREATE_OPUS_ENCODER;
    return MAGNETARVOIP_ERROR;
  }

  capture_config.pUserData = opus_encoder;

	if (ma_device_init(NULL, &capture_config, &capture_device) != MA_SUCCESS)
	{
		error_type = FAILED_TO_INITIALIZE_CAPTURE_DEVICE;
		return MAGNETARVOIP_ERROR;
	}

	if (ma_device_start(&capture_device) != MA_SUCCESS)
	{
		ma_device_uninit(&capture_device);
		error_type = FAILED_TO_START_CAPTURE_DEVICE;
		return MAGNETARVOIP_ERROR;
	}

	return 0;
}

int32_t stop_miniaudio_capture()
{
	ma_device_uninit(&capture_device);
  opus_encoder_destroy(opus_encoder);
	return 0;	
}
