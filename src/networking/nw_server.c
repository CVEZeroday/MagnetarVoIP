/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: nw_server.c           */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <re/re.h>

#include "nw.h"
#include "nw_server.h"
#include "settings.h"
#include "macros.h"

// Variable Definition 

int32_t init_nwserver()
{

  return 0;
}

int32_t send_tcp_server(const void* buffer, size_t size)
{
//  DEBUG_PRINTF("send_nwserver called\n");
  tcp_multicast(buffer, size);

  return 0;
}

int32_t send_rtp_server(const uint8_t* data, size_t size, uint32_t timestamp)
{
  rtp_multicast(data, size, timestamp);

  return 0;
}

int32_t close_nwserver()
{
  close_nw_tcp();
  close_nw_rtp();
  return 0;
}
