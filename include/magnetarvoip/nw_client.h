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
int32_t send_nwclient(const void* buffer, size_t size);

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
