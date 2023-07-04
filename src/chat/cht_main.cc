/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*          File Name: cht_main.cc          */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <thread>
#include <mutex>
#include <queue>
#include <chrono>

#include <string.h>

#include "cht.h"
#include "macros.h"
#include "settings.h"
#include "nw.h"
#include "core_thread.h"

int32_t chat_main()
{
  while (ProgramStatus != WORKING);
  DEBUG_PRINTF("Entering Chat Main...\n");

  char _name[20];
  char _str[2000];
  uint32_t _time;
  uint32_t _header;

  // Main Loop
  while (ProgramStatus != KILL)
  {
    if (!chatRecvQueue.empty())
    {
      mtx_lock(&mutex_chat);
      strncpy(_name, (const char*)chatRecvQueue.front()->data.chat.name, 20);
      strncpy(_str, (const char*)chatRecvQueue.front()->data.chat.str, 2000);
      _time = chatRecvQueue.front()->data.chat.time;
      _header = chatRecvQueue.front()->data.chat.header;
      chatRecvQueue.pop();
      mtx_unlock(&mutex_chat);

      DEBUG_PRINTF("\n%s: %s\n", _name, _str);
    }
  }

  return 0;
}
