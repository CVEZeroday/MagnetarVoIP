/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: nw_send_rtp.cc          */
/*   Created by CVE_zeroday on 22.06.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <stdint.h>
#include <string.h>

#include <re/re.h>
#include <re/rem.h>

#include "nw_interface.h"
#include "macros.h"
#include "settings.h"

struct mbuf* mbuffer = NULL;
struct rtp_sock* send_rtp_sock = NULL;
struct sa send_rtp_addr;

uint16_t seq;

struct rtcp_stats send_stats;
uint32_t ssrc;

uint8_t send_rtp(const uint8_t* data, size_t size, uint32_t timestamp)
{
  int32_t err;

  mbuffer->pos = mbuffer->end = RTP_HEADER_SIZE;
  err = mbuf_write_mem(mbuffer, data, size);
  if (err)
    return 1;

  mbuffer->pos = RTP_HEADER_SIZE;
  err = rtp_send(send_rtp_sock, &send_rtp_addr, false, true, RTP_PAYLOAD_TYPE, timestamp, tmr_jiffies_rt_usec(), mbuffer);
  if (err)
    return 1;
  DEBUG_PRINTF("rtp packet sent!\n");

  return 0;
}

uint8_t init_send_rtp()
{
  int err;

  seq = 0;
  ssrc = RTP_SSRC_MAIN;

  memset(&send_rtp_addr, 0, sizeof(send_rtp_addr));
  memset(&send_stats, 0, sizeof(send_stats));

  sa_init(&send_rtp_addr, AF_INET);

  err = sa_set_str(&send_rtp_addr, Address, Port);
  if (err)
  {
    mem_deref(send_rtp_sock);
    DEBUG_PRINTF("sa_set_str err: %d\n", err);
    return 1;
  }

  err = rtp_listen(&send_rtp_sock, IPPROTO_UDP, &send_rtp_addr, RTP_MIN_PORT, RTP_MAX_PORT, true, rtp_recv_handler, NULL, NULL);
  if (err)
  {
    mem_deref(send_rtp_sock);
    DEBUG_PRINTF("rtp_listen err: %d\n", err);
    return 1;
  }

  err = udp_local_get(rtp_sock(send_rtp_sock), &send_rtp_addr);
  if (err)
  {
    mem_deref(send_rtp_sock);
    DEBUG_PRINTF("udp_local_get err: %d\n", err);
    return 1;
  }

  mbuffer = mbuf_alloc(1024);
  if (!mbuffer)
  {
    mem_deref(send_rtp_sock);
    DEBUG_PRINTF("mbuf alloc err: %d\n", err);
    return 1;
  }

  DEBUG_PRINTF("Send_rtp initiated!\n");
  return 0;
}

void close_send_rtp()
{
  mem_deref(send_rtp_sock);
  mem_deref(mbuffer);
}
