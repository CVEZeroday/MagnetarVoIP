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
#include <re/re.h>

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


thrd_t core_thread;
thrd_t chat_thread;
thrd_t ux_thread;

mtx_t mutex_status;

extern "C" {
  mtx_t mutex_chat;
  mtx_t mutex_aio;
  
  int32_t(*send_nw_tcp)(const void* buffer, size_t size);
  int32_t(*send_nw_rtp)(const uint8_t* buffer, size_t size, uint32_t timestamp);
}
