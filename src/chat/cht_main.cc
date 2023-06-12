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

#include "cht.h"
#include "macros.h"
#include "settings.h"
#include "nw.hpp"
#include "core_thread.h"

int32_t chat_main()
{
  while (ProgramStatus != WORKING);
  DEBUG_PRINTF("Entering Chat Main...\n");

  std::string _name;
  std::string _str;
  uint32_t _time;
  uint32_t _header;

  // Main Loop
  while (ProgramStatus != KILL)
  {
    if (!chatRecvQueue.empty())
    {
      mutex_chat.lock();
      _name = (char*)chatRecvQueue.front()->data.chat.name;
      _str = (char*)chatRecvQueue.front()->data.chat.str;
      _time = chatRecvQueue.front()->data.chat.time;
      _header = chatRecvQueue.front()->data.chat.header;
      chatRecvQueue.pop();
      mutex_chat.unlock();

      DEBUG_PRINTF("\n%s: %s\n", _name.c_str(), _str.c_str());
    }
  }

  return 0;
}
