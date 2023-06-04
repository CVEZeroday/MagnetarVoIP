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
static std::thread core_thread;
static std::thread chat_thread;
static std::thread ux_thread;
#endif

int init_threads();

void packer_yield();

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
