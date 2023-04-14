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

void returnError(int);
class NetworkingClient;
class NetworkingServer;
class NetworkingSession;

typedef enum PACKETTYPE : unsigned char {
  PACKETTYPE_CHAT,
  PACKETTYPE_AUDIO,
  PACKETTYPE_NETWORK,
  PACKETTYPE_INSTRUCTION,
  PACKETTYPE_ETC
} PACKETTYPE;

typedef struct NW_PACKET {
  PACKETTYPE type;
  unsigned char header1;
  unsigned char header2;
  unsigned char header3;
  union {
    std::string str;
    std::vector<int> pcm;
    unsigned short int uint8;
    unsigned int uint16;
    unsigned long long int uint64;
  } packet_data;
} NW_PACKET;

/********************************************/
#endif
