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
#ifdef __cplusplus
#include "nw.hpp"

extern "C" {
#endif
/********************************************/

extern int(*send_nw)(const void* buffer, size_t size);

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
