#ifndef __CHT_H__
#define __CHT_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*            File Name: cht.h              */
/*   Created by CVE_zeroday on 12.04.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************/
#include "macros.h"

int32_t chat_main();
int32_t send_chat(char* str);

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
