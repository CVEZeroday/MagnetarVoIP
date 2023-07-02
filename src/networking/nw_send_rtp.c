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
struct rtp_sock *send_rtp_sock = NULL;
struct sa send_rtp_addr;

uint16_t seq;

struct rtcp_stats send_stats;
uint32_t ssrc;

uint8_t send_rtp(const uint8_t* data, size_t size, uint32_t timestamp)
{
  struct rtp_header header;
  int32_t err;

  memset(&header, 0, sizeof(header));
  header.ver = RTP_VERSION;
  header.seq = seq++;
  header.ts = timestamp;
  header.ssrc = ssrc;

  err = rtp_hdr_encode(mbuffer, &header);
  if (err)
  {
    mbuf_reset(mbuffer);
    return 1;
  }
  mbuf_write_mem(mbuffer, data, size);
  mbuffer->pos = 0;

  err = udp_send(rtp_sock(send_rtp_sock), &send_rtp_addr, mbuffer);
  if (err)
  {
    mbuf_reset(mbuffer);
    return 1;
  }
  DEBUG_PRINTF("rtp packet sent!\n");

  mbuf_reset(mbuffer);
  return 0;
}

uint8_t init_send_rtp()
{
  int err;

  seq = 0;
  ssrc = RTP_SSRC_MAIN;

  memset(&send_rtp_addr, 0, sizeof(send_rtp_addr));
  memset(&send_stats, 0, sizeof(send_stats));

  err = sa_set_str(&send_rtp_addr, Address, Port);
  if (err)
  {
    mem_deref(send_rtp_sock);
    return 1;
  }

  err = rtp_listen(&send_rtp_sock, IPPROTO_UDP, &send_rtp_addr, RTP_MIN_PORT, RTP_MAX_PORT, true, rtp_recv_handler, NULL, NULL);
  if (err)
  {
    mem_deref(send_rtp_sock);
    return 1;
  }

  err = udp_local_get(rtp_sock(send_rtp_sock), &send_rtp_addr);
  if (err)
  {
    mem_deref(send_rtp_sock);
    return 1;
  }

  mbuffer = mbuf_alloc(1024);
  if (!mbuffer)
  {
    mem_deref(send_rtp_sock);
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
