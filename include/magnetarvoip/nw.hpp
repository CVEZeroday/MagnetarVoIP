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

typedef enum : unsigned char {
  PACKETTYPE_CHAT,
  PACKETTYPE_AUDIO,
  PACKETTYPE_NETWORK,
  PACKETTYPE_INSTRUCTION,
  PACKETTYPE_ETC
} PACKETTYPE;

typedef union {
  std::string str;
  std::vector<int> pcm;
  unsigned short int uint8;
  unsigned long int uint16;
  unsigned long long int uint64;
} PACKETDATA;

typedef struct {
  PACKETTYPE type;
  unsigned char header[3];
  PACKETDATA data;
 } NW_PACKET;
// NW_PACKET struct
// type : 1 Byte
// header : 3 Bytes
// data : 2~ Bytes

/********************************************/
#endif
