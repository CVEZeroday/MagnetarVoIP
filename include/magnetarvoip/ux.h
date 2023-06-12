#ifndef __UX_H__
#define __UX_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*             File Name: ux.h              */
/*   Created by CVE_zeroday on 12.04.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

#include "macros.h"

int32_t ux_main();

//int32_t gui_init();
//int32_t tui_init();
int32_t cli_init();

/********************************************/
#ifdef __cplusplus
}
#endif
#endif

