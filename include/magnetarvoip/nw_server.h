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
int32_t send_nwserver(const void* buffer, size_t size);

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
