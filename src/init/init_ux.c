/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*          File Name: init_ux.c            */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <stdio.h>

#include "init_ux.h"
#include "settings.h"
#include "macros.h"

int init_ux()
{
    if (ProgramMode == CLI_MODE)
        Initialized |= CLI_FLAG;

    if (ProgramMode == TUI_MODE)
        Initialized |= TUI_FLAG;

    if (ProgramMode == GUI_MODE)
        Initialized |= GUI_FLAG;

    Initialized |= UX_FLAG;

    return 0;
}