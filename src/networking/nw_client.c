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

int32_t init_nwclient()
{
  init_nw_tcp();

  tcp_admin.id = 0;
  sa_set_str(&tcp_admin.sa, Address, TCP_CHAT_PORT);

  return 0;
}

int32_t send_nwclient(const void* buffer, size_t size)
{ 
//  DEBUG_PRINTF("send_nwclient called\n");
  send_tcp(buffer, size, &tcp_admin);

  return 0;
}

int32_t close_nwclient()
{

  return 0;
}
