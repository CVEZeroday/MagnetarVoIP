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

int init_threads()
{
  DEBUG_PRINTF("Initializing Threads...\n");
  core_thread = CppCommon::Thread::Start(core_main);
  chat_thread = CppCommon::Thread::Start(chat_main);
  ux_thread = CppCommon::Thread::Start(ux_main);
  // nw_thread is managed by cppserver library
  // audio_thread is managed by miniaudio library

  core_thread.join();
  chat_thread.join();
  ux_thread.join();

  return 0;
}

void packer_yield()
{
  CppCommon::Thread::Yield();
}

int close_threads()
{
  return 0;
}
