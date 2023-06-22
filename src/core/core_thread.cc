/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: core_thread.cc         */
/*   Created by CVE_zeroday on 01.04.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <threads/thread.h>

#include "core_thread.h"

#include "core.h"
#include "cht.h"
#include "ux.h"
#include "macros.h"
#include "settings.h"
#include "nw_interface.h"

int32_t init_threads()
{
  DEBUG_PRINTF("Initializing Threads...\n");
  core_thread = CppCommon::Thread::Start(core_main);
  chat_thread = CppCommon::Thread::Start(chat_main);
  ux_thread = CppCommon::Thread::Start(ux_main);
  // nw_thread is managed by cppserver library
  // audio_thread is managed by miniaudio library
  changeProgramStatus(WORKING);
  DEBUG_PRINTF("Initialized Threads! ProgramStatus: %d\n", ProgramStatus);

  core_thread.join();
  chat_thread.join();
  ux_thread.join();

  return 0;
}

void packer_yield()
{
  CppCommon::Thread::Yield();
}

void changeProgramStatus(int32_t status)
{
  mutex_status.lock();
  ProgramStatus = status;
  mutex_status.unlock();
}

int32_t close_threads()
{
  return 0;
}
