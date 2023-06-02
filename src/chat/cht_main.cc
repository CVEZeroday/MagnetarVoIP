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

#include "cht.h"
#include "macros.h"
#include "queue.h"
#include "nw_interface.h"

int chat_main()
{
  while(1)
    if (Initialized & CHAT_FLAG)
      break;
  // Check if CHAT_FLAG initialized
  
  std::string dequeuedStr;

  // Main Loop
  while(1)
  {
    if (!isEmptyQueue(&chatPacketQueue))
    {
      mutex_chat.lock();
      dequeuedStr = dequeue(&chatPacketQueue, string);
      mutex_chat.unlock();
    }
  }

  return 0;
}
