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

#include "nw_client.hpp"
#include "nw_server.hpp"
#include "settings.h"
#include "macros.h"

#include "nw.hpp"
#include "nw_client.hpp"
#include "nw_server.hpp"
#include "nw_interface.h"

#include "init_network.hpp"

int32_t init_tcp()
{  
  if (IsServer)
  {
    send_nw = send_nwserver;
    if (init_nwserver() == MAGNETARVOIP_ERROR)
      return MAGNETARVOIP_ERROR;
  }
  else
  {
    send_nw = send_nwclient;
    if (init_nwclient() == MAGNETARVOIP_ERROR)
      return MAGNETARVOIP_ERROR;
  }

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

  return init_send_rtp() | init_recv_rtp();
}
