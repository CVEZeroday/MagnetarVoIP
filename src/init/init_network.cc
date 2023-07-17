/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: init_network.cc         */
/*   Created by CVE_zeroday on 09.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.h"
#include "nw_client.h"
#include "nw_server.h"
#include "nw_interface.h"
#include "settings.h"
#include "macros.h"

#include "init_network.h"

int32_t init_network()
{  
  mtx_init(&mutex_tcp_count, mtx_plain);
  mtx_init(&mutex_aio, mtx_plain);
  mtx_init(&mutex_chat, mtx_plain);

  if (IsServer)
  {
    send_nw_tcp = send_tcp_server;
    send_nw_rtp = send_rtp_server;
    if (init_nwserver() == MAGNETARVOIP_ERROR)
      return MAGNETARVOIP_ERROR;
  }
  else
  {
    send_nw_tcp = send_tcp_client;
    send_nw_rtp = send_rtp_client;
    if (init_nwclient() == MAGNETARVOIP_ERROR)
      return MAGNETARVOIP_ERROR;
  }

  init_nw_tcp();
  init_rescp();

  return 0;
}

uint8_t init_rtp()
{
  libre_exception_btrace(true);
  int err = libre_init();
  if (err)
  {
    DEBUG_PRINTF("libre initiation err: %d\n", err);
    re_thread_async_close();
    libre_close();
    return 1;
  }
  DEBUG_PRINTF("Libre initiated!\n");

  return init_nw_rtp();
}
