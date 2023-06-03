#ifndef __NW_INTERFACE_H__
#define __NW_INTERFACE_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_interface.h         */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <thread>
#include <mutex>

#include "nw.hpp"
#include "queue.h"

// Packet Queues

static Queue chatPacketQueue;
static Queue audioPacketQueue;

static std::mutex mutex_chat;
static std::mutex mutex_aio;

// inline functions

inline void packetReceivedHandler(const void* buffer, unsigned long size)
{
    if (((const NW_PACKET*)buffer)->type == PACKETTYPE_CHAT)
    {
        // Chatting Interface
        mutex_chat.lock();
        enqueue(&chatPacketQueue, ((const NW_PACKET*)buffer)->data.str, string);
        mutex_chat.unlock();
    }
    if (((const NW_PACKET*)buffer)->type == PACKETTYPE_AUDIO)
    {
       // Miniaudio Interface, have to pcm data to audiobuf 
    }
}

#endif