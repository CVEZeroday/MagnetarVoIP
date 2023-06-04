/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*     File Name: init_miniaudio.c          */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <stdio.h>

#include "magnetar.h"
#include "init_miniaudio.h"
#include "aio.h"

#include <miniaudio/miniaudio.h>

int init_miniaudio()
{
	DEBUG_PRINTF("Initializing miniaudio capture module...\n");
	if (init_miniaudio_capture() == MAGNETARVOIP_ERROR)
		return MAGNETARVOIP_ERROR;

	DEBUG_PRINTF("Initializing miniaudio playback module...\n");
	if (init_miniaudio_playback() == MAGNETARVOIP_ERROR)
		return MAGNETARVOIP_ERROR;

	return 0;
}
