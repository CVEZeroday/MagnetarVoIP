/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_packer.cc           */
/*   Created by CVE_zeroday on 04.07.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.h"

void packetReceivedHandler(const void* buffer, uint32_t size)
{
  if (((const NW_PACKET*)buffer)->type == PACKETTYPE_CHAT)
  {
    //DEBUG_PRINTF("packetReceivedHandler: recvd str: %s\n", ((const NW_PACKET*)buffer)->data.chat.str);
    // Chatting Interface
    mtx_lock(&mutex_chat);
    chatRecvQueue.push((const NW_PACKET*)buffer);
    mtx_unlock(&mutex_chat);
  }

  if (((const NW_PACKET*)buffer)->type == PACKETTYPE_INSTRUCTION)
  {

  }

  if (((const NW_PACKET*)buffer)->type == PACKETTYPE_ERROR)
  {

  }
}
