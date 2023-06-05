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
#include "threads/thread.h"

#include "magnetar.h"
#include "init.h"
#include "queue.h"
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

Queue chatPacketQueue;
Queue audioPacketQueue;

std::mutex mutex_chat;
std::mutex mutex_aio;

std::thread core_thread;
std::thread chat_thread;
std::thread ux_thread;

std::mutex mutex_status;

void init_externs()
{
  initQueue(&chatPacketQueue);
  initQueue(&audioPacketQueue);
}
