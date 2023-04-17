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

int ux_main()
{
  while(1)
    if(Initialized & UX_FLAG)
      break;
  // Check if UX_FLAG initialized
  
  return 0;
}
