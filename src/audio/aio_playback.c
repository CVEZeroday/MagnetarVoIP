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

#include <miniaudio/miniaudio.h>

ma_device playback_device;
ma_device_config playback_config;

void playback_data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
	// data_callback
}

int init_miniaudio_playback()
{
	playback_config = ma_device_config_init(ma_device_type_playback);

	playback_config.playback.format = ma_format_s32;
	playback_config.playback.channels = 2;
	playback_config.wasapi.noAutoConvertSRC = MA_TRUE;
	playback_config.dataCallback = playback_data_callback;

	//if (ma_device_init(NULL, &))

	return 0;
}