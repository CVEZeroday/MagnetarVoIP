/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: nw_recv_rtp.cc          */
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

struct rtp_sock *recv_rtp_sock = NULL;
struct sa recv_rtp_addr;

struct rtcp_stats recv_stats;
extern uint32_t ssrc;

void rtp_recv_handler(const struct sa *src, const struct rtp_header* header, struct mbuf* mbuffer, void* arg)
{
  DEBUG_PRINTF("rtp recvd!\n");

}

uint8_t init_recv_rtp()
{
  int err;

  ssrc = 1;

  memset(&recv_rtp_addr, 0, sizeof(recv_rtp_addr));
  memset(&recv_stats, 0, sizeof(recv_stats));

  err = sa_set_str(&recv_rtp_addr, Address, Port+1);
  if (err)
  {
    mem_deref(recv_rtp_sock);
    return 1;
  }

  err = rtp_listen(&recv_rtp_sock, IPPROTO_UDP, &recv_rtp_addr, RTP_MIN_PORT, RTP_MAX_PORT, true, rtp_recv_handler, NULL, NULL);
  if (err)
  {
    mem_deref(recv_rtp_sock);
    return 1;
  }

  err = udp_local_get(rtp_sock(recv_rtp_sock), &recv_rtp_addr);
  if (err)
  {
    mem_deref(recv_rtp_sock);
    return 1;
  }

  DEBUG_PRINTF("Recv_rtp initiated!\n");
  return 0;
}

void close_recv_rtp()
{
  mem_deref(recv_rtp_sock);
}
