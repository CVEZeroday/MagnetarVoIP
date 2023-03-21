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

#include <miniaudio/miniaudio.h>

ma_device device;
ma_device_config capture_config;

void capture_data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
	//data callback
}

int init_miniaudio_capture()
{
	capture_config = ma_device_config_init(ma_device_type_capture);

	capture_config.capture.format = ma_format_s32;
	capture_config.capture.channels = 2;
	capture_config.wasapi.noAutoConvertSRC = MA_TRUE;
	capture_config.dataCallback = capture_data_callback;

	if (ma_device_init(NULL, &capture_config, &device) != MA_SUCCESS)
		return FAILED_TO_INITIALIZE_CAPTURE_DEVICE;

	if (ma_device_start(&device) != MA_SUCCESS)
	{
		ma_device_uninit(&device);
		return FAILED_TO_START_CAPTURE_DEVICE;
	}

	return 0;
}

int stop_miniaudio_capture()
{
	ma_device_uninit(&device);

	return 0;	
}