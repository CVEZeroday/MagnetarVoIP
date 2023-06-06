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
#include "settings.h"
#include "aio.h"
#include "core_thread.h"
#include "nw_interface.h"

int error_type = -1; 

int ProgramMode = PROGRAMMODE_DEFAULT;
char IsServer = ISSERVER_DEFAULT;
char Address[0x10] = ADDRESS_DEFAULT;
int Port = PORT_DEFAULT;
int TestMode = TESTMODE_DEFAULT;
int ProgramStatus = PROGRAMSTATUS_DEFAULT;

std::queue<NW_PACKET> chatSendQueue;
std::queue<const NW_PACKET*>chatRecvQueue;
std::queue<int> audioSendQueue;
std::queue<int> audioRecvQueue;

std::mutex mutex_chat;
std::mutex mutex_aio;

std::thread core_thread;
std::thread chat_thread;
std::thread ux_thread;

std::mutex mutex_status;

extern "C" {
  int(*send_nw)(const void* buffer, size_t size);
}
