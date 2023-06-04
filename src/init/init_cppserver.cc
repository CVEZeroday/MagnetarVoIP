/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*      File Name: init_cppserver.cc        */
/*   Created by CVE_zeroday on 09.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw_client.hpp"
#include "nw_server.hpp"
#include "settings.h"
#include "macros.h"
#include "queue.h"

#include "nw.hpp"
#include "nw_client.hpp"
#include "nw_server.hpp"
#include "nw_interface.h"

#include "init_cppserver.hpp"

int init_cppserver()
{  
  initQueue(&chatPacketQueue);
  initQueue(&audioPacketQueue);

  if (IsServer)
  {
    if (init_nwserver() == MAGNETARVOIP_ERROR)
      return MAGNETARVOIP_ERROR;
  }
  else
  {
    if (init_nwclient() == MAGNETARVOIP_ERROR)
      return MAGNETARVOIP_ERROR;
  }

  return 0;
}
