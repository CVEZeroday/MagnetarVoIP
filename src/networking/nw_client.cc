/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_client.cc           */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <re/re.h>

#include "nw.hpp"
#include "nw_client.hpp"
#include "settings.h"
#include "macros.h"

// Variable Definition
struct tcp_sock* tcp_sock_clnt;
struct tcp_conn* tcp_conn_clnt_recvr;
struct tcp_conn* tcp_conn_clnt_sendr;

void tcp_client_recvr_recv_handler(struct mbuf *mb, void *arg)
{

}


void tcp_client_recvr_close_handler(int err, void *arg)
{

}


void tcp_client_recvr_conn_handler(const struct sa *peer, void *arg)
{
	int err;

	(void)peer;

	err = tcp_accept(&tcp_conn_clnt_recvr, tcp_sock_clnt, NULL, tcp_client_recvr_recv_handler, tcp_client_recvr_close_handler, NULL);
	if (err) {
		return;
	}
}


void tcp_client_sendr_estab_handler(void *arg)
{

}

void tcp_client_sendr_recv_handler(struct mbuf* mb, void *arg)
{

}

void tcp_client_sendr_close_handler(int err, void *arg)
{
}

int32_t init_nwclient()
{
  int32_t err;
  struct sa sa_clnt_send, sa_clnt_recv;

  err = sa_set_str(&sa_clnt_send, Address, TCP_CHAT_PORT);
  if (err)
  {
    mem_deref(tcp_sock_clnt);
    mem_deref(tcp_conn_clnt_recvr);
    mem_deref(tcp_conn_clnt_sendr);
    return 1;
  }

  err = tcp_listen(&tcp_sock_clnt, &sa_clnt_recv, tcp_client_recvr_conn_handler, NULL);
  if (err)
  {
    mem_deref(tcp_sock_clnt);
    mem_deref(tcp_conn_clnt_recvr);
    mem_deref(tcp_conn_clnt_sendr);
    return 1;
  }

  err = tcp_local_get(tcp_sock_clnt, &sa_clnt_send);
  if (err)
  {
    mem_deref(tcp_sock_clnt);
    mem_deref(tcp_conn_clnt_recvr);
    mem_deref(tcp_conn_clnt_sendr);
    return 1;
  }

  err = tcp_connect(&tcp_sock_clnt, &sa_clnt_send, tcp_client_sendr_estab_handler, tcp_client_sendr_recv_handler, tcp_client_sendr_close_handler, NULL);
  if (err)
  {
    mem_deref(tcp_sock_clnt);
    mem_deref(tcp_conn_clnt_recvr);
    mem_deref(tcp_conn_clnt_sendr);
    return 1;
  }

  return 0;
}

int32_t send_nwclient(const void* buffer, size_t size)
{

  return 0;
}

int32_t close_nwclient()
{
  mem_deref(tcp_sock_clnt);
  mem_deref(tcp_conn_clnt_recvr);
  mem_deref(tcp_conn_clnt_sendr);
  return 0;
}
