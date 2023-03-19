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

#include "magnetar.h"
#include "aio.h"

#include <miniaudio/miniaudio.h>

int init_miniaudio_capture()
{
	ma_device_config capture_config = ma_device_config_init(ma_device_type_capture);
	capture_config.capture.format = ma_format_s32;
	capture_config.capture.channels = 2;
	capture_config.wasapi.noAutoConvertSRC = MA_TRUE;

	return 0;
}