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

#include <re/re.h>

#include "core_thread.h"

#include "core.h"
#include "cht.h"
#include "ux.h"
#include "macros.h"
#include "settings.h"
#include "nw_interface.h"


static int _core_main(void* arg)
{
  return core_main();
}

static int _chat_main(void* arg)
{
  return chat_main();
}

static int _ux_main(void* arg)
{
  return ux_main();
}

int32_t init_threads(void* arg)
{
  int32_t err = 0;
  DEBUG_PRINTF("Initializing Threads...\n");

  err |= thread_create_name(&core_thread, "core_thread", _core_main, NULL);
  err |= thread_create_name(&chat_thread, "chat_thread", _chat_main, NULL);
  err |= thread_create_name(&ux_thread, "ux_thread", _ux_main, NULL);
  if (err)
  {
    DEBUG_PRINTF("Thread Initialization failed!\n");
    return 1;
  }
  
  
  mtx_init(&mutex_status, mtx_plain);

  changeProgramStatus(WORKING);

  DEBUG_PRINTF("Initialized Threads! ProgramStatus: %d\n", ProgramStatus);

  thrd_join(core_thread, &err);
  thrd_join(chat_thread, &err);
  thrd_join(ux_thread, &err);

  return 0;
}

void changeProgramStatus(int32_t status)
{
  mtx_lock(&mutex_status);
  ProgramStatus = status;
  mtx_unlock(&mutex_status);
}

int32_t close_threads()
{
  return 0;
}
