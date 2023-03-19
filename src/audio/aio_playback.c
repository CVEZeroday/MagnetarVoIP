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

#include "magnetar.h"
#include "aio.h"

#include <miniaudio/miniaudio.h>

int init_miniaudio_playback()
{
	ma_device_config playback_config = ma_device_config_init(ma_device_type_playback);
	playback_config.playback.format = ma_format_s32;
	playback_config.playback.channels = 2;
	playback_config.wasapi.noAutoConvertSRC = MA_TRUE;

	return 0;
}