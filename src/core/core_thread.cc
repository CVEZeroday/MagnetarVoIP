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

std::thread core_thread;
std::thread chat_thread;
std::thread ux_thread;

int init_threads()
{
	core_thread = CppCommon::Thread::Start(core_main);
	chat_thread = CppCommon::Thread::Start(chat_main);
	ux_thread = CppCommon::Thread::Start(ux_main);
	// nw_thread is managed by cppserver library
	// audio_thread is managed by miniaudio library
  
  return 0;
}

int close_threads()
{
  return 0;
}
