/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*           File Name: core.c              */
/*   Created by CVE_zeroday on 01.04.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "core.h"
#include "settings.h"
#include "macros.h"
#include "core_thread.h"

int core_main()
{
  while (ProgramStatus != WORKING);
  DEBUG_PRINTF("Entering Core Main...\n");
  
  while (ProgramStatus != KILL)
  {

  }
  return 0;
}
