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
#include "core_thread.h"

int chat_main()
{  
  DEBUG_PRINTF("Entering Chat Main...\n");

  std::string dequeuedStr;

  // Main Loop
  while(1)
  {
    if (!isEmptyQueue(&chatPacketQueue))
    {
      mutex_chat.lock();
      dequeuedStr = dequeue_string(&chatPacketQueue);
      mutex_chat.unlock();
    }
  }

  return 0;
}
