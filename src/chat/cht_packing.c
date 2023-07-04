/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: cht_packing.cc         */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <string.h>
#include <malloc.h>

#include "nw.h"

#include "cht.h"
#include "nw_interface.h"
#include "macros.h"

int32_t send_chat(char* str)
{
  NW_PACKET* _packet = (NW_PACKET*)malloc(2029);
  _packet->type = PACKETTYPE_CHAT;
  strncpy((char*)_packet->data.chat.str, str, 2000);
  strncpy((char*)_packet->data.chat.name, "temp_name", 10);

  send_nw(_packet, sizeof(*_packet));
  free(_packet);

  return 0;
}
