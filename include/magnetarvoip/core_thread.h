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

#include <re/re.h>

#include "macros.h"

extern thrd_t core_thread;
extern thrd_t chat_thread;
extern thrd_t ux_thread;

extern mtx_t mutex_status;

int32_t init_threads();
void changeProgramStatus(int32_t status);

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
