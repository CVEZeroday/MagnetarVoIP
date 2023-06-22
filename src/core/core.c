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
#include "nw_interface.h"
#include "aio.h"

int32_t core_main()
{
  while (ProgramStatus != WORKING);
  DEBUG_PRINTF("Entering Core Main...\n");
  
  while (ProgramStatus != KILL)
  {

  }

  finalizeProgram();
  return 0;
}

void finalizeProgram()
{
  stop_miniaudio_playback();
  stop_miniaudio_capture();
  close_send_rtp();
  close_recv_rtp();
  close_nwserver();
  close_nwclient();
}
