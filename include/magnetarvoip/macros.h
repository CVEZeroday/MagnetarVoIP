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

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#define M_MAJOR 0
#define M_MINOR 0
#define M_PATCH 1
#define VERSION_STRINGIFY(x) #x
#define MAKE_VERSION_STRING(major, minor, patch) VERSION_STRINGIFY(major) "." VERSION_STRINGIFY(minor) "." VERSION_STRINGIFY(patch)
#define M_VERSION MAKE_VERSION_STRING(M_MAJOR, M_MINOR, M_PATCH)
#define MAGNETARVOIP_VERSION M_VERSION

#define RTP_CONN_COUNT 5

#define INSTRUCTION_PORT 30200
#define TCP_CHAT_PORT 30201
#define RTP_PORT(num) ((0 < num && num <= RTP_CONN_COUNT) ? 30203 + (num) * 2 : 30203)

#define LOWEST_DELAY_SETTING 1
#define MAGNETARVOIP_DEBUG 1

#define MAGNETARVOIP_ERROR -1

/* Initialization error */
#define INIT_MINIAUDIO_ERROR 5000
#define INIT_CPPSERVER_ERROR 5001
#define INIT_CLI_ERROR 5002
#define INIT_TUI_ERROR 5003

/* Initialize of capture, playback error */
#define FAILED_TO_INITIALIZE_CAPTURE_DEVICE 5100
#define FAILED_TO_START_CAPTURE_DEVICE 5101
#define FAILED_TO_INITIALIZE_PLAYBACK_DEVICE 5102
#define FAILED_TO_START_PLAYBACK_DEVICE 5103
#define FAILED_TO_CREATE_OPUS_ENCODER 5104
#define FAILED_TO_CREATE_OPUS_DECODER 5105

/* Send Packet Error */
#define FAILED_TO_SEND_PACKET 5200

/* Initialization Flag */
/*
extern uint32_t Initialized = 0b00000000; //core, network, chat, audio, ux, cli, tui, gui
#define CORE_FLAG		0b10000000
#define NETWORK_FLAG	0b01000000
#define CHAT_FLAG		0b00100000
#define AUDIO_FLAG		0b00010000
#define UX_FLAG			0b00001000
#define CLI_FLAG		0b00000100
#define TUI_FLAG		0b00000010
#define GUI_FLAG		0b00000001
*/

/* File Paths */
#define CLI_HISTORY_FILE "./cli_history.txt"

/* Debug Macros */

#if MAGNETARVOIP_DEBUG
#define DEBUG_PRINTF(...) printf(__VA_ARGS__);
#else
#define DEBUG_PRINTF(...) 0
#endif // MAGNETARVOIP_DEBUG

/* Audio Settings */

#if LOWEST_DELAY_SETTING
#define APPLICATION OPUS_APPLICATION_RESTRICTED_LOWDELAY
#else
#define APPLICATION OPUS_APPLICATION_VOIP
#endif

#define SAMPLE_RATE 48000
#define BITRATE 16000
#define CHANNELS 1
#define FRAME_SIZE 480 // 10ms

/* RTP Settings */

#define RTP_PAYLOAD_TYPE 96
#define RTP_SSRC_MAIN 1

/*
#define RTP_ERR(err) \
  if ((err)) { \
    DEBUG_PRINTF("Rtp Error: %d", (err)); \
    return 1; \
  }
*/

/* RERTCP Settings */


/* Error Type */

extern int32_t error_type;

#endif
