#ifndef __CLI_H__
#define __CLI_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*            File Name: cli.h              */
/*   Created by CVE_zeroday on 04.06.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

#include <stdlib.h>

#include "macros.h"
#include "settings.h"

// Function Prototypes

int32_t cli_loop();
char* draw_cli(const char* prefix);

//int32_t printDescription(int32_t id);
char** parse(char* input, int32_t* count);

static const char* prompt_prefix = "\x1b[1;30;47m  Magnetar  \x1b[0;37;40m\uE0B0 ";
//

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
