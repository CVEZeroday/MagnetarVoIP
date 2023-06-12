#ifndef __INIT_UX_H__
#define __INIT_UX_H__
/********************************************/
/* This header file is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: init_cli.h            */
/*   Created by CVE_zeroday on 15.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

#include "macros.h"

int32_t init_cli();
int32_t init_tui();
int32_t init_ux();

/********************************************/
#ifdef __cplusplus
}
#endif

#endif
