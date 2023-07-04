/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*           File Name: nw_tcp.c            */
/*   Created by CVE_zeroday on 04.07.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <malloc.h>

#include <re/re.h>

#include "nw.h"
#include "settings.h"
#include "macros.h"

// Variable Definition
struct tcp_sock* tcp_sock;
struct tcp_conn* tcp_conn;

void tcp_recvr_recv_handler(struct mbuf *mbuffer, void *arg)
{
  NW_PACKET* packet = (NW_PACKET*)malloc(2029);
  mbuf_read_mem(mbuffer, (uint8_t*)packet, sizeof(NW_PACKET));
  
  packetReceivedHandler(packet, sizeof(*packet));
}


void tcp_recvr_close_handler(int err, void *arg)
{
  DEBUG_PRINTF("TCP client receiver closed!\n");

}

void tcp_recvr_conn_handler(const struct sa *peer, void *arg)
{
	int err;

	(void)peer;

	err = tcp_accept(&tcp_conn, tcp_sock, NULL, tcp_recvr_recv_handler, tcp_recvr_close_handler, NULL);
	if (err) {
		return;
	}
}

int32_t init_nwclient()
{
  int32_t err;
  struct sa sa_clnt;

  err = sa_set_str(&sa_clnt, Address, TCP_CHAT_PORT);
  if (err)
  {
    mem_deref(tcp_sock);
    return 1;
  }

  err = tcp_listen(&tcp_sock, &sa_clnt, tcp_recvr_conn_handler, NULL);
  if (err)
  {
    mem_deref(tcp_sock);
    return 1;
  }

  return 0;
}

int32_t close_nwclient()
{
  mem_deref(tcp_sock);
  return 0;
}

// TCP Client Sender

void tcp_sendr_estab_handler(void *arg)
{
  DEBUG_PRINTF("TCP client sender established!\n");

}

void tcp_sendr_close_handler(int err, void *arg)
{
  DEBUG_PRINTF("TCP client sender closed!\n");

}

int32_t new_tcp_init(tcp* tcp)
{
  int err;

  struct sa sa_clnt;
  err = sa_set_str(&sa_clnt, tcp->address, tcp->port);
  if (err)
  {
    mem_deref(tcp_sock);
    return 1;
  }

  err = tcp_connect(&tcp->tcp_conn, &sa_clnt, tcp_sendr_estab_handler, NULL, tcp_sendr_close_handler, tcp);
  if (err)
  {
    mem_deref(tcp_sock);
    return 1;
  }

  return 0;
}

int32_t send_tcp(const void* buffer, size_t size, tcp* tcp)
{
  struct mbuf mbuffer;
  int err;

  mbuf_init(&mbuffer);

  err = mbuf_write_mem(&mbuffer, (const uint8_t*)buffer, size);
  if (err)
  {
    mbuf_reset(&mbuffer);
    return 1;
  }
  mbuffer.pos = 0;

  err = tcp_send(tcp->tcp_conn, &mbuffer);
  if (err)
  {
    mbuf_reset(&mbuffer);
    return 1;
  }

  return 0;
}

