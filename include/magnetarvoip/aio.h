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

#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

int init_miniaudio_capture();
int init_miniaudio_playback();

/********************************************/
#ifdef __cplusplus
}
#endif