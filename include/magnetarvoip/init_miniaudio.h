#pragma once
/********************************************/
/* This header file is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*      File Name: init_miniaudio.h         */
/*   Created by CVE_zeroday on 15.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

<<<<<<< HEAD
int init_miniaudio();

/********************************************/
#ifdef __cplusplus
}
#endif
=======
#define MA_NO_DECODING
#define MA_NO_ENCODING
#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio/miniaudio.h>

int init_miniaudio();
>>>>>>> parent of f6cab97 (2023.3.16)
