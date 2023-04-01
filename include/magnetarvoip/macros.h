#ifndef __MACROS_H__
#define __MACROS_H__
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

#define VERSION "0.0.0.1"

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

/* Send Packet Error */
#define FAILED_TO_SEND_PACKET 5008


/* Initialization Flag */
int Initialized = 0b00000000; //core, network, chat, audio, ux, cli, tui, gui
#define CORE_FLAG		0b10000000
#define NETWORK_FLAG	0b01000000
#define CHAT_FLAG		0b00100000
#define AUDIO_FLAG		0b00010000
#define UX_FLAG			0b00001000
#define CLI_FLAG		0b00000100
#define TUI_FLAG		0b00000010
#define GUI_FLAG		0b00000001

#endif