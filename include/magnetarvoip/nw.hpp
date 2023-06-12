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
#include <mutex>
#include <queue>
#include <chrono>

#include "macros.h"
#include "nw_interface.h"

void returnError(int32_t);

extern std::queue<NW_PACKET> chatSendQueue;
extern std::queue<const NW_PACKET*> chatRecvQueue;
extern std::queue<int32_t> audioSendQueue;
extern std::queue<int32_t> audioRecvQueue;

extern std::mutex mutex_chat;
extern std::mutex mutex_aio;

// inline functions

inline void packetReceivedHandler(const void* buffer, uint32_t size)
{
    if (((const NW_PACKET*)buffer)->type == PACKETTYPE_CHAT)
    {
        //DEBUG_PRINTF("packetReceivedHandler: recvd str: %s\n", ((const NW_PACKET*)buffer)->data.chat.str);
        // Chatting Interface
        mutex_chat.lock();
        chatRecvQueue.push((const NW_PACKET*)buffer);
        mutex_chat.unlock();
    }
    if (((const NW_PACKET*)buffer)->type == PACKETTYPE_AUDIO)
    {
       // Miniaudio Interface, have to pcm data to audiobuf 
    }
}

/********************************************/
#endif
