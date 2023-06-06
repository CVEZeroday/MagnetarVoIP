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
#include "nw_interface.h"
#include "core_thread.h"

int chat_main()
{
  while (ProgramStatus != WORKING);
  DEBUG_PRINTF("Entering Chat Main...\n");

  std::string _name;
  std::string _str;
  std::chrono::system_clock::time_point _time;
  unsigned long int _header;

  // Main Loop
  while (ProgramStatus != KILL)
  {
    if (!chatRecvQueue.empty())
    {
      mutex_chat.lock();
      _name = chatRecvQueue.front()->data.chat.name;
      _str = chatRecvQueue.front()->data.chat.str;
      _time = chatRecvQueue.front()->data.chat.time;
      _header = chatRecvQueue.front()->data.chat.header;
      chatRecvQueue.pop();
      mutex_chat.unlock();

      DEBUG_PRINTF("received msg. %s: %s (%d)", _name.c_str(), _str.c_str(), (int)std::chrono::system_clock::to_time_t(_time));
    }
  }

  return 0;
}
