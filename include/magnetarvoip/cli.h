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

#include "linenoise/linenoise.h"

#include <stdlib.h>

// Function Prototypes

int cli_loop();
void completionHook(char const* prefix, linenoiseCompletions* lc);

int printDescription(int id);
char** parse(char* input, int* count);

static char const* prompt_prefix = "\x1b[1;32mMagnetar\x1b[0m> ";

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
