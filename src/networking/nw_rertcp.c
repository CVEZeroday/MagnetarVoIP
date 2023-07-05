/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: nw_rertcp.c           */
/*   Created by CVE_zeroday on 04.07.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <malloc.h>

#include "khash.h"

#include "nw.h"
#include "macros.h"

KHASH_MAP_INIT_INT(tcp_hashmap, tcp_t*)
khash_t(tcp_hashmap)* tcp_conn_hash;

KHASH_MAP_INIT_INT(rtp_hashmap, rtp_t*)
khash_t(rtp_hashmap)* rtp_conn_hash;

/* rtp hashmap wrapper */

void new_rtp_conn(rtp_t* rtp)
{
  int ret;
  khint_t k;
  k = kh_put(rtp_hashmap, rtp_conn_hash, rtp->id, &ret);
  if (!ret) kh_del(rtp_hashmap, rtp_conn_hash, k);
  kh_value(rtp_conn_hash, k) = rtp;
}

void delete_rtp_conn(rtp_t* rtp)
{
  khint_t k;
  k = kh_get(rtp_hashmap, rtp_conn_hash, rtp->id);
  kh_del(rtp_hashmap, rtp_conn_hash, k);
}

int32_t get_rtp_conn(uint16_t id, rtp_t* rtp)
{
  khint_t k;
  k = kh_get(rtp_hashmap, rtp_conn_hash, id);
  if (k == kh_end(rtp_conn_hash)) return 1;
  rtp = kh_value(rtp_conn_hash, k);

  return 0;
}

/* tcp hashmap wrapper */

void new_tcp_conn(tcp_t* tcp)
{
  int ret;
  khint_t k;
  k = kh_put(tcp_hashmap, tcp_conn_hash, tcp->id, &ret);
  if (!ret) kh_del(tcp_hashmap, tcp_conn_hash, k);
  kh_value(tcp_conn_hash, k) = tcp;
}

void delete_tcp_conn(tcp_t* tcp)
{
  khint_t k;
  k = kh_get(tcp_hashmap, tcp_conn_hash, tcp->id);
  kh_del(tcp_hashmap, tcp_conn_hash, k);
}

int32_t get_tcp_conn(uint16_t id, tcp_t* tcp)
{
  khint_t k;
  k = kh_get(tcp_hashmap, tcp_conn_hash, id);
  if (k == kh_end(tcp_conn_hash)) return 1;
  tcp = kh_value(tcp_conn_hash, k);

  return 0;
}

void tcp_multicast(const void* data, size_t size)
{
  khint_t k;
  for (k = kh_begin(tcp_conn_hash); k != kh_end(tcp_conn_hash); k++)
  {
    send_tcp(data, size, kh_value(tcp_conn_hash, k));
  }
}

int32_t init_rertcp()
{
  tcp_conn_hash = kh_init(tcp_hashmap);
  rtp_conn_hash = kh_init(rtp_hashmap);

  return 0;
}

void close_rertcp()
{
  kh_destroy(tcp_hashmap, tcp_conn_hash);
  kh_destroy(rtp_hashmap, rtp_conn_hash);
}
