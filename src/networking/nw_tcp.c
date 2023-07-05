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

/* Variable Definition */

struct tcp_sock* tcp_sock;
struct sa sa_clnt;

mtx_t mutex_tcp_count;
uint32_t tcp_count;
/* id 0 is initial admin */

void tcp_estab_handler(void* arg)
{
  new_tcp_conn((tcp_t*)arg);
}

void tcp_recv_handler(struct mbuf *mbuffer, void *arg)
{
  NW_PACKET* packet = (NW_PACKET*)malloc(2029);
  mbuf_read_mem(mbuffer, (uint8_t*)packet, sizeof(NW_PACKET));
  
  packetReceivedHandler(packet, sizeof(*packet));
}


void tcp_close_handler(int err, void *arg)
{
  delete_tcp_conn((tcp_t*)arg);
}

void tcp_conn_handler(const struct sa *peer, void *arg)
{
	int err;
  
  tcp_t* _tcp = (tcp_t*)malloc(sizeof(tcp_t));
  _tcp->tcp_conn = NULL;
  _tcp->sa = *peer;
  mtx_lock(&mutex_tcp_count);
  _tcp->id = ++tcp_count;
  mtx_unlock(&mutex_tcp_count);

	err = tcp_accept(&_tcp->tcp_conn, tcp_sock, tcp_estab_handler, tcp_recv_handler, tcp_close_handler, _tcp);
	if (err) {
		return;
	}
}

int32_t init_nw_tcp()
{
  int32_t err;
  tcp_count = 0;

  err = sa_set_str(&sa_clnt, Address, TCP_CHAT_PORT);
  if (err)
  {
    mem_deref(tcp_sock);
    return 1;
  }

  err = tcp_listen(&tcp_sock, &sa_clnt, tcp_conn_handler, NULL);
  if (err)
  {
    mem_deref(tcp_sock);
    return 1;
  }

  return 0;
}

int32_t close_nw_tcp()
{
  mem_deref(tcp_sock);
  return 0;
}

// TCP Client Sender

int32_t new_tcp_init(tcp_t* tcp, bool admin)
{
  int err;

  mtx_lock(&mutex_tcp_count);
  if (admin) tcp->id = 0;
  else tcp->id = ++tcp_count;
  mtx_unlock(&mutex_tcp_count);

  err = tcp_connect(&tcp->tcp_conn, &tcp->sa, tcp_estab_handler, tcp_recv_handler, tcp_close_handler, tcp);
  if (err)
  {
    mem_deref(tcp_sock);
    return 1;
  }

  return 0;
}

int32_t send_tcp(const void* buffer, size_t size, tcp_t* tcp)
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

