/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: aio_playback.c          */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
<<<<<<< HEAD:src/audio/aio_playback.c
/********************************************/

#include "magnetar.h"
#include "aio.h"

int init_miniaudio_playback()
{
	ma_device_config playback_config = ma_device_config_init(ma_device_type_playback);
	playback_config.playback.format = ma_format_s32;
	playback_config.playback.channels = 2;
	playback_config.wasapi.noAutoConvertSRC = MA_TRUE;

	return 0;
}
=======
/********************************************/
>>>>>>> parent of f6cab97 (2023.3.16):src/networking/audio/aio_configure.c
