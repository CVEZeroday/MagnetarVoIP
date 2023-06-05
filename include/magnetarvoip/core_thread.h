#ifndef __CORE_THREAD_H__
#define __CORE_THREAD_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: core_thread.h          */
/*   Created by CVE_zeroday on 15.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

#ifdef __cplusplus
}
#include "threads/thread.h"
#include <mutex>

extern std::thread core_thread;
extern std::thread chat_thread;
extern std::thread ux_thread;

extern std::mutex mutex_status;

extern "C" {
#endif

int init_threads();
void changeProgramStatus(int status);
void packer_yield();

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
