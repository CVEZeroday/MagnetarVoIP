#pragma once
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*            File Name: nw.h               */
/*   Created by CVE_zeroday on 28.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#define PACKETTYPE_CHAT 4000
#define PACKETTYPE_AUDIO 4001


inline void packetReceivedHander(const void* buffer, unsigned long size);


typedef struct NW_PACKET {
    unsigned short type;
    void* packet_data;
} NW_PACKET;