#ifndef __SETTINGS_H__
#define __SETTINGS_H__
/********************************************/
/* This header file is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: settings.h            */
/*   Created by CVE_zeroday on 15.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "macros.h"

  enum PROGRAM_MODE {
    CLI_MODE,
    GUI_MODE,
    TUI_MODE
  };
  extern uint8_t ProgramMode;
#define PROGRAMMODE_DEFAULT CLI_MODE
  extern uint8_t IsServer;
#define ISSERVER_DEFAULT 1

/* ip addr of initial admin */
  extern char Address[0x10];
#define ADDRESS_DEFAULT "127.0.0.1"
  extern uint16_t Port;
#define PORT_DEFAULT 30200
#define RTP_MIN_PORT 1024
#define RTP_MAX_PORT 49152

  extern uint8_t TestMode;
#define TESTMODE_DEFAULT 0

  enum PROGRAM_STAT {
    INIT,
    WORKING,
    KILL
  };
  extern uint8_t ProgramStatus;
#define PROGRAMSTATUS_DEFAULT INIT

#ifdef __cplusplus
}
#endif

#endif
