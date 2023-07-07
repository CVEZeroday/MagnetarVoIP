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

struct tcp_sock* tcp_socket = NULL;
struct mbuf* tcp_mbuffer = NULL;

mtx_t mutex_tcp_count;
uint32_t tcp_count;
/* id 0 is initial admin */

void tcp_estab_handler(void* arg)
{
  DEBUG_PRINTF("tcp_estab_handler: tcp conn established\n");
  new_tcp_conn((tcp_t*)arg);
}

void tcp_recv_handler(struct mbuf *tcp_mbuffer, void *arg)
{
  NW_PACKET* packet = (NW_PACKET*)malloc(sizeof(NW_PACKET));
  mbuf_read_mem(tcp_mbuffer, (uint8_t*)packet, sizeof(NW_PACKET));
  /* get packet data except for str */
  int len = packet->data.chat.len;
  
  NW_PACKET* tmp = packet;
  packet = realloc(packet, sizeof(NW_PACKET) + len + 1);
  if (packet == NULL)
  {
    free(tmp);
    DEBUG_PRINTF("tcp_recv_handler: realloc failed.\n");
    return;
  }
  tmp = 0;

  mbuf_read_mem(tcp_mbuffer, packet->data.chat.str, len);

  packetReceivedHandler(packet, sizeof(*packet));
  free(packet);
}


void tcp_close_handler(int err, void *arg)
{
  DEBUG_PRINTF("tcp_close_handler: tcp conn closed\n");
  delete_tcp_conn((tcp_t*)arg);
  free((tcp_t*)arg);
}

void tcp_conn_handler(const struct sa *peer, void *arg)
{
  DEBUG_PRINTF("tcp_conn_handler: new tcp conn accepting...\n");
	int err;
  
  tcp_t* _tcp = (tcp_t*)malloc(sizeof(tcp_t));
  _tcp->tcp_conn = NULL;
  _tcp->sa = *peer;
  mtx_lock(&mutex_tcp_count);
  _tcp->id = ++tcp_count;
  mtx_unlock(&mutex_tcp_count);

	err = tcp_accept(&_tcp->tcp_conn, tcp_socket, tcp_estab_handler, tcp_recv_handler, tcp_close_handler, _tcp);
	if (err) {
		return;
	}
}

int32_t init_nw_tcp()
{
  int32_t err;
  struct sa sa_clnt;
  tcp_count = 0;

  mbuf_init(tcp_mbuffer);

  err = sa_set_str(&sa_clnt, "0.0.0.0", TCP_CHAT_PORT);
  if (err)
  {
    mem_deref(tcp_socket);
    return 1;
  }

  err = tcp_listen(&tcp_socket, &sa_clnt, tcp_conn_handler, NULL);
  if (err)
  {
    mem_deref(tcp_socket);
    return 1;
  }

  DEBUG_PRINTF("init_nw_tcp: listening tcp\n");
  return 0;
}

void close_nw_tcp()
{
  mem_deref(tcp_socket);
  mem_deref(tcp_mbuffer);
}

// TCP Sender

int32_t new_tcp_init(tcp_t* tcp, bool admin)
{
  int err;

  mtx_lock(&mutex_tcp_count);
  if (admin) tcp->id = 0;
  else tcp->id = ++tcp_count;
  mtx_unlock(&mutex_tcp_count);

  DEBUG_PRINTF("new_tcp_init: new tcp connecting...\n");
  err = tcp_connect(&tcp->tcp_conn, &tcp->sa, tcp_estab_handler, tcp_recv_handler, tcp_close_handler, tcp);
  if (err)
  {
    mem_deref(tcp_socket);
    return 1;
  }

  return 0;
}

int32_t send_tcp(const void* buffer, size_t size, tcp_t* tcp)
{
  int err;

  err = mbuf_write_mem(tcp_mbuffer, (const uint8_t*)buffer, size);
  if (err)
  {
    mbuf_reset(tcp_mbuffer);
    return 1;
  }

  tcp_mbuffer->pos = 0;
  err = tcp_send(tcp->tcp_conn, tcp_mbuffer);
  if (err)
  {
    mbuf_reset(tcp_mbuffer);
    DEBUG_PRINTF("send_tcp: tcp_send err: %d\n", err);
    return 1;
  }
  DEBUG_PRINTF("send_tcp: data sent!\n");

  return 0;
}

