#ifndef __NW_CLIENT_H__
#define __NW_CLIENT_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: nw_client.h           */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.h"

#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

// Function Definition

int32_t init_nwclient();
int32_t send_tcp_client(const void* buffer, size_t size);
int32_t send_rtp_client(const uint8_t* data, size_t size, uint32_t timestamp);

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
