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

#include <re/re.h>

#include "macros.h"
#include "nw_interface.h"
#include "re_thread.h"

#ifdef __cplusplus

#include <string>
#include <vector>
#include <thread>
#include <queue>
#include <chrono>

extern std::queue<NW_PACKET> chatSendQueue;
extern std::queue<const NW_PACKET*> chatRecvQueue;
extern std::queue<int32_t> audioSendQueue;
extern std::queue<int32_t> audioRecvQueue;

#endif

#ifdef __cplusplus
extern "C" {
#endif

extern mtx_t mutex_chat;
extern mtx_t mutex_aio;

/* Structure Definition */

typedef struct tcp {
  struct tcp_conn* tcp_conn;
  char address[0x10];
  uint16_t port;
  uint8_t type;
} tcp;

typedef struct udp {
  struct udp_conn* udp_conn;
  char address[0x10];
  uint16_t port;
  uint8_t type;
} udp;

typedef struct rtp {
  struct rtp_conn* rtp_conn;
  char address[0x10];
  uint16_t port;
  uint8_t type;
} rtp;

void returnError(int32_t);
void packetReceivedHandler(const void* buffer, uint32_t size);
int32_t send_tcp(const void* buffer, size_t size, tcp* tcp);

/* rertcp */

int32_t init_rertcp();

/********************************************/
#ifdef __cplusplus
}
#endif

#endif
