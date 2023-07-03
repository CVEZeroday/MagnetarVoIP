#ifndef __NW_HPP__
#define __NW_HPP__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*            File Name: nw.hpp             */
/*   Created by CVE_zeroday on 25.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
/* THIS FILE CANNOT BE INCLUDED IN .c FILES */

#include <string>
#include <vector>
#include <thread>
#include <queue>
#include <chrono>

#include <re/re.h>

#include "macros.h"
#include "nw_interface.h"
#include "re_thread.h"

void returnError(int32_t);

extern std::queue<NW_PACKET> chatSendQueue;
extern std::queue<const NW_PACKET*> chatRecvQueue;
extern std::queue<int32_t> audioSendQueue;
extern std::queue<int32_t> audioRecvQueue;

extern mtx_t mutex_chat;
extern mtx_t mutex_aio;

// inline functions

inline void packetReceivedHandler(const void* buffer, uint32_t size)
{
  if (((const NW_PACKET*)buffer)->type == PACKETTYPE_CHAT)
  {
    //DEBUG_PRINTF("packetReceivedHandler: recvd str: %s\n", ((const NW_PACKET*)buffer)->data.chat.str);
    // Chatting Interface
    mtx_lock(&mutex_chat);
    chatRecvQueue.push((const NW_PACKET*)buffer);
    mtx_unlock(&mutex_chat);
  }
  /*
  if (((const NW_PACKET*)buffer)->type == PACKETTYPE_AUDIO)
  {
    // Miniaudio Interface, have to pcm data to audiobuf 

    DEBUG_PRINTF("audio recvd: %d\n", ((const NW_PACKET*)buffer)->data.audio.pcm[0]);
  }
  */
}

/********************************************/
#endif
