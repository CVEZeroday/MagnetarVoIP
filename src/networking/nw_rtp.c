/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*           File Name: nw_rtp.c            */
/*   Created by CVE_zeroday on 22.06.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <netinet/in.h>
#include <stdint.h>
#include <string.h>

#include <re/re.h>
#include <re/rem.h>

#include "nw.h"
#include "nw_interface.h"
#include "macros.h"
#include "settings.h"

/* recvr */
struct rtp_sock* rtp_socket;
struct rtcp_stats recv_stats;


/* sendr */
uint16_t seq;
struct mbuf* rtp_mbuffer = NULL;
struct rtcp_stats send_stats;
uint32_t ssrc;

void rtp_recv_handler(const struct sa *src, const struct rtp_header* header, struct mbuf* rtp_mbuffer, void* arg)
{
  DEBUG_PRINTF("rtp recvd!\n");

}

int32_t init_nw_rtp()
{
  int err;
  struct sa sa_clnt;
  
  seq = 0;
  ssrc = RTP_SSRC_MAIN;

  mbuf_init(rtp_mbuffer);
  memset(&recv_stats, 0, sizeof(recv_stats));
  memset(&send_stats, 0, sizeof(send_stats));

  err = sa_set_str(&sa_clnt, "0.0.0.0", RTP_PORT(0));
  if (err)
  {
    mem_deref(rtp_socket);
    return 1;
  }

  err = rtp_listen(&rtp_socket, IPPROTO_UDP, &sa_clnt, RTP_MIN_PORT, RTP_MAX_PORT, true, rtp_recv_handler, NULL, NULL);
  if (err)
  {
    mem_deref(rtp_socket);
    DEBUG_PRINTF("rtp_listen err: %d\n", err);
    return 1;
  }

  DEBUG_PRINTF("Recv_rtp initiated!\n");
  return 0;
}

void close_nw_rtp()
{
  mem_deref(rtp_socket);
  mem_deref(rtp_mbuffer);
}

// RTP Sender

int32_t send_rtp(const uint8_t* data, size_t size, uint32_t timestamp, rtp_t* rtp)
{
  int32_t err;

  rtp_mbuffer->pos = rtp_mbuffer->end = RTP_HEADER_SIZE;
  err = mbuf_write_mem(rtp_mbuffer, data, size);
  if (err)
  {
    mbuf_reset(rtp_mbuffer);
    return 1;
  }

  rtp_mbuffer->pos = RTP_HEADER_SIZE;
  err = rtp_send(rtp_socket, &rtp->sa, false, true, RTP_PAYLOAD_TYPE, timestamp, tmr_jiffies_rt_usec(), rtp_mbuffer);
  if (err)
  {
    mbuf_reset(rtp_mbuffer);
    return 1;
  }
  //DEBUG_PRINTF("rtp packet sent!\n");

  return 0;
}
