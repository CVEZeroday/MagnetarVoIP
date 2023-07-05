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
  int32_t len = strlen(str);
  NW_PACKET* _packet = (NW_PACKET*)malloc(sizeof(NW_PACKET) + len + 1);
  _packet->data.chat.len = len;
  _packet->type = PACKETTYPE_CHAT;
  strncpy((char*)_packet->data.chat.str, str, len);
  strncpy((char*)_packet->data.chat.name, "temp_name", 32);

  send_nw(_packet, sizeof(*_packet));
  free(_packet);

  return 0;
}
