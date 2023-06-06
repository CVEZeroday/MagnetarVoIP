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

void returnError(int);

typedef enum : unsigned char {
  PACKETTYPE_CHAT,
  PACKETTYPE_AUDIO,
  PACKETTYPE_NETWORK,
  PACKETTYPE_INSTRUCTION,
  PACKETTYPE_ERROR,
  PACKETTYPE_ETC
} PACKETTYPE;

typedef struct _CHATPACKET
{
  unsigned long int header;
  std::string name;
  std::string str;
  //unsigned long int time;
  std::chrono::system_clock::time_point time;
  _CHATPACKET()
  {
    header = 0;
    name = "";
    str = "";
    time = std::chrono::system_clock::now();
  }
} CHATPACKET;

typedef struct _AUDIOPACKET
{
  std::vector<int> pcm;

  _AUDIOPACKET() {}
} AUDIOPACKET;
// 480 samples

typedef union _PACKETDATA
{
  CHATPACKET chat;
  AUDIOPACKET audio;

  _PACKETDATA() {}
} PACKETDATA;

typedef struct _NW_PACKET
{
  PACKETTYPE type;
  PACKETDATA data;

  _NW_PACKET() {}
 } NW_PACKET;
// NW_PACKET struct
// type : 1 Byte

extern std::queue<NW_PACKET> chatSendQueue;
extern std::queue<const NW_PACKET*> chatRecvQueue;
extern std::queue<int> audioSendQueue;
extern std::queue<int> audioRecvQueue;

extern std::mutex mutex_chat;
extern std::mutex mutex_aio;

// inline functions

inline void packetReceivedHandler(const void* buffer, unsigned long size)
{
    if (((const NW_PACKET*)buffer)->type == PACKETTYPE_CHAT)
    {
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
