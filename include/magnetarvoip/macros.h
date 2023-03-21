#pragma once
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*          File Name: macros.h             */
/*   Created by CVE_zeroday on 15.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#define ERROR -1

/* Initialization error */
#define INIT_MINIAUDIO_ERROR 5000
#define INIT_CPPSERVER_ERROR 5001
#define INIT_CLI_ERROR 5002
#define INIT_TUI_ERROR 5003

/* Initialize of capture, playback error */
#define FAILED_TO_INITIALIZE_CAPTURE_DEVICE 5004
#define FAILED_TO_START_CAPTURE_DEVICE 5005
#define FAILED_TO_INITIALIZE_PLAYBACK_DEVICE 5006
#define FAILED_TO_START_PLAYBACK_DEVICE 5007