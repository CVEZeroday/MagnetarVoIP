/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: nw_client.c           */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <re/re.h>

#include "nw.h"
#include "nw_client.h"
#include "settings.h"
#include "macros.h"

tcp_t tcp_admin;
rtp_t rtp_admin;

int32_t init_nwclient()
{
  tcp_admin.id = 0;
  sa_set_str(&tcp_admin.sa, Address, TCP_CHAT_PORT);
  new_tcp_init(&tcp_admin, true);

  return 0;
}

int32_t send_tcp_client(const void* buffer, size_t size)
{ 
//  DEBUG_PRINTF("send_nwclient called\n");
  send_tcp(buffer, size, &tcp_admin);

  return 0;
}

int32_t send_rtp_client(const uint8_t* data, size_t size, uint32_t timestamp)
{
  send_rtp(data, size, timestamp, &rtp_admin);

  return 0;
}

int32_t close_nwclient()
{
  close_nw_tcp();
  close_nw_rtp();
  return 0;
}
