/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: aio_playback.c          */
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

ma_device playback_device;
ma_device_config playback_config;
OpusDecoder* opus_decoder;

void playback_data_callback(ma_device* pDevice, void* pOutput, const void* pInput, uint32_t frameCount)
{
	// data_callback
  if (jitter_buffer == NULL) return;

  int8_t* buffer = (int8_t*)g_async_queue_try_pop(jitter_buffer);
  if (buffer == NULL) 
  {
    DEBUG_PRINTF("No data from jitter buffer.\n");
    return;
  }

  int32_t samplesToDecode = frameCount * pDevice->playback.channels * pDevice->sampleRate / 1000;
  int16_t pcmBuffer[samplesToDecode];
  int32_t samplesDecoded = opus_decode(opus_decoder, (const uint8_t*)buffer, 480, pcmBuffer, samplesToDecode, 0);

  if (samplesDecoded < 0)
  {
    fprintf(stderr, "Decoding Error: %d\n", samplesDecoded);
    return;
  }

  for (size_t i = 0; i < samplesDecoded; i++)
  {
    ((int32_t*)pOutput)[i] = ((int32_t)pcmBuffer[i]) << 16;
  }

  free(buffer);
}

int32_t init_miniaudio_playback()
{
	playback_config = ma_device_config_init(ma_device_type_playback);

	playback_config.playback.format = ma_format_s16;
	playback_config.playback.channels = 1;
  playback_config.sampleRate = SAMPLE_RATE;
	playback_config.wasapi.noAutoConvertSRC = MA_TRUE;
	playback_config.dataCallback = playback_data_callback;

  playback_config.periods = 1;
  playback_config.periodSizeInFrames = 480;

  int32_t opus_decoder_err;
  opus_decoder = opus_decoder_create(SAMPLE_RATE, CHANNELS, &opus_decoder_err);
  if (opus_decoder_err < 0)
  {
    error_type = FAILED_TO_CREATE_OPUS_DECODER;
    return MAGNETARVOIP_ERROR;
  }

	if (ma_device_init(NULL, &playback_config, &playback_device) != MA_SUCCESS)
	{
		error_type = FAILED_TO_INITIALIZE_PLAYBACK_DEVICE;
		return MAGNETARVOIP_ERROR;
	}

	if (ma_device_start(&playback_device) != MA_SUCCESS)
	{
		ma_device_uninit(&playback_device);
		error_type = FAILED_TO_START_PLAYBACK_DEVICE;
		return MAGNETARVOIP_ERROR;
	}

	return 0;
}

int32_t stop_miniaudio_playback()
{
	ma_device_uninit(&playback_device);
  opus_decoder_destroy(opus_decoder);
	return 0;
}
