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

#include <string>

#include "cht.h"
#include "nw_interface.h"

int send_chat(char *str)
{
  NW_PACKET _packet;
  _packet.type = PACKETTYPE_CHAT;
  _packet.data.chat.str = std::string(str);
  _packet.data.chat.name = "temp_name";

  send_nw(&_packet, sizeof(_packet));

  return 0;
}
