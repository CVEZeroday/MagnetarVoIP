#ifndef __NW_INTERFACE_H__
#define __NW_INTERFACE_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_interface.h         */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.h"

// inline functions

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

#endif