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

#include <re/re.h>

#ifdef __cplusplus

extern "C" {
#endif
/********************************************/
#include <stddef.h>
#include "macros.h"

extern int32_t(*send_nw)(const void* buffer, size_t size);

uint8_t send_rtp(const uint8_t* data, size_t size, uint32_t timestamp);
void rtp_recv_handler(const struct sa *src, const struct rtp_header* header, struct mbuf* mbuffer, void* arg);
uint8_t init_send_rtp();
uint8_t init_recv_rtp();
void close_send_rtp();
void close_recv_rtp();

int32_t close_nwserver();
int32_t close_nwclient();

typedef enum {
  PACKETTYPE_CHAT,
  PACKETTYPE_AUDIO,
  PACKETTYPE_NETWORK,
  PACKETTYPE_INSTRUCTION,
  PACKETTYPE_ERROR,
  PACKETTYPE_ETC
} PACKETTYPE;

typedef struct _CHATPACKET
{
  uint32_t header;
  int8_t name[20];
  int8_t str[2000];
  uint32_t time;
  //std::chrono::system_clock::time_point time;
} CHATPACKET;
// 4 + 20 + 2000 + 4 = 2028

/*
typedef struct _AUDIOPACKET
{
  uint8_t pcm[480];
} AUDIOPACKET;
*/

typedef union _PACKETDATA
{
  CHATPACKET chat;
  //AUDIOPACKET audio;
} PACKETDATA;

typedef struct _NW_PACKET
{
  uint8_t type;
  PACKETDATA data;
 } NW_PACKET;
// NW_PACKET struct
// type : 1 Byte
// data : 1920 bytes if audiopacket
// data : 2028 bytes if chatpacket
// sum : 1921 bytes if audiopacket
// sum : 2029 bytes if chatpacket

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
