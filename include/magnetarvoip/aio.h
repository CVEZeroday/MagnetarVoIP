#pragma once
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*            File Name: aio.h              */
/*   Created by CVE_zeroday on 16.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#define MA_NO_DECODING
#define MA_NO_ENCODING
#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio/miniaudio.h>

int init_miniaudio_capture();
int init_miniaudio_playback();