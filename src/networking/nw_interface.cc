/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: nw_interface.cc         */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.h"

inline void packetReceivedHandler(const void* buffer, unsigned long size)
{
    if (((const NW_PACKET*)buffer)->type == PACKETTYPE_CHAT)
    {
        // Chatting Interface
    }
    if (((const NW_PACKET*)buffer)->type == PACKETTYPE_AUDIO)
    {
        
    }
}