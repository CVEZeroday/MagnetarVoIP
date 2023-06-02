/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: cli_interface.c         */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linenoise/linenoise.h"
#include "macros.h"

static const char* commands[] = {
  "/c", "/connect", "/con",
  "/dc", "/disconnect", "/dcon",
  "\\",
  "/s", "/setting",
  "/vu", "/volup", "/volumeup",
  "/vd", "/voldown", "/volumedown",
  "/vs", "/volset", "/volumesetting",
  "/iu", "/inup", "/inputup",
  "/id", "/indown", "/inputdown",
  "/is", "/inset", "/inputsetting",
  "/m", "/mute",
  "/h", "/help", "/?",
  "/i", "/info",
  NULL
};

void completionHook(char const* prefix, linenoiseCompletions* lc)
{
  for (size_t i = 0; commands[i] != NULL; i++)
  {
    if (strncmp(prefix, commands[i], strlen(prefix)) == 0)
    {
      linenoiseAddCompletion(lc, commands[i]);
    }
  }
}

int cli_init()
{
  linenoiseInstallWindowChangeHandler();

  const char* file = CLI_HISTORY_FILE;

  linenoiseHistoryLoad(file);
  linenoiseSetCompletionCallback(completionHook);

  char const* prompt = "\x1b[1;32mMagnetar\x1b[0m> ";

  while(1)
  {
    char* result = linenoise(prompt);
    
    if (result == NULL)
    {
      break;
    }
    else if (!strncmp(result, "/history", 8))
    {
      for (int i = 0; ; i++)
      {
        char* history = linenoiseHistoryLine(i);
        if (history == NULL) break;
        printf("%4d: %s\n", i, history);
        free(history);
      }
    }
    if (*result == '\0')
    {
      free(result);
      break;
    }
  }

  return 0;
}
