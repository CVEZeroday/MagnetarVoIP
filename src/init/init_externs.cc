/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: init_externs.cc        */
/*   Created by CVE_zeroday on 05.06.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <mutex>
#include <queue>
#include "threads/thread.h"

#include "magnetar.h"
#include "init.h"
#include "macros.h"
#include "settings.h"
#include "aio.h"
#include "core_thread.h"
#include "nw_interface.h"

int32_t error_type = -1; 

uint8_t ProgramMode = PROGRAMMODE_DEFAULT;
uint8_t IsServer = ISSERVER_DEFAULT;
char Address[0x10] = ADDRESS_DEFAULT;
uint16_t Port = PORT_DEFAULT;
uint8_t TestMode = TESTMODE_DEFAULT;
uint8_t ProgramStatus = PROGRAMSTATUS_DEFAULT;

std::queue<NW_PACKET> chatSendQueue;
std::queue<const NW_PACKET*>chatRecvQueue;
std::queue<int32_t> audioSendQueue;
std::queue<int32_t> audioRecvQueue;

std::mutex mutex_chat;
std::mutex mutex_aio;

std::thread core_thread;
std::thread chat_thread;
std::thread ux_thread;

std::mutex mutex_status;

extern "C" {
  int32_t(*send_nw)(const void* buffer, size_t size);
}
