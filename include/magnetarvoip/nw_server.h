#ifndef __NW_SERVER_H__
#define __NW_SERVER_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: nw_server.h           */
/*   Created by CVE_zeroday on 15.04.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.h"

#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

// Function Definition
int32_t init_nwserver();
int32_t send_tcp_server(const void* buffer, size_t size);
int32_t send_rtp_server(const uint8_t* data, size_t size, uint32_t timestamp);

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
