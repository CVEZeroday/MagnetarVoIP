#ifndef __NW_H__
#define __NW_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*             File Name: nw.h              */
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
  struct sa sa;
  uint8_t type;
  uint8_t id;
} tcp_t;

typedef struct udp {
  struct sa sa;
  uint8_t type;
  uint8_t id;
} udp_t;

typedef struct rtp {
  struct sa sa;
  uint8_t type;
  uint8_t id;
} rtp_t;

void returnError(int32_t);
void packetReceivedHandler(const void* buffer, uint32_t size);
int32_t send_tcp(const void* buffer, size_t size, tcp_t* tcp);
int32_t init_nw_tcp();
void close_nw_tcp();

int32_t send_rtp(const uint8_t* data, size_t size, uint32_t timestamp, rtp_t* rtp);
int32_t init_nw_rtp();
void close_nw_rtp();

/* rertcp */

int32_t init_rescp();
void close_rescp();

void new_rtp_conn(rtp_t* rtp);
void delete_rtp_conn(rtp_t* rtp);
int32_t get_rtp_conn(uint16_t id, rtp_t* rtp);
void rtp_multicast(const void* buffer, size_t size, uint32_t timestamp);

void new_tcp_conn(tcp_t* tcp);
void delete_tcp_conn(tcp_t* tcp);
int32_t get_tcp_conn(uint16_t id, tcp_t* tcp);
void tcp_multicast(const void* buffer, size_t size);

/********************************************/
#ifdef __cplusplus
}
#endif

#endif
