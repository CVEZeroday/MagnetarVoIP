/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*          File Name: ux_main.c            */
/*   Created by CVE_zeroday on 01.04.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "ux.h"
#include "macros.h"
#include "settings.h"

int ux_main()
{
  DEBUG_PRINTF("Entering UX Main...\n");

  if (ProgramMode == GUI_MODE)
  {
    //gui_init();
  }
  if (ProgramMode == TUI_MODE)
  {
    //tui_init();
  }
  if (ProgramMode == CLI_MODE)
  {
    DEBUG_PRINTF("Initializing CLI Mode...\n");
    cli_init();
  }

  return 0;
}
