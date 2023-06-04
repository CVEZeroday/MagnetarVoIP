/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: cli_interpret.c         */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cli.h"
#include "cmd.h"
#include "linenoise/linenoise.h"
#include "macros.h"

int cmd_callback_connect(int argn, char** args)
{

  return 0;
}

int cmd_callback_disconnect(int argn, char** args)
{

  return 0;
}

int cmd_callback_setting(int argn, char** args)
{

  return 0;
}

int cmd_callback_volumeup(int argn, char** args)
{

  return 0;
}

int cmd_callback_volumedown(int argn, char** args)
{

  return 0;
}

int cmd_callback_volumesetting(int argn, char** args)
{
  
  return 0;
}

int cmd_callback_inputup(int argn, char** args)
{

  return 0;
}

int cmd_callback_inputdown(int argn, char** args)
{
  
  return 0;
}

int cmd_callback_inputsetting(int argn, char** args)
{
  
  return 0;
}

int cmd_callback_mute(int argn, char** args)
{

  return 0;
}

int cmd_callback_help(int argn, char** args)
{

  return 0;
}

int cmd_callback_info(int argn, char** args)
{

  return 0;
}

int cmd_callback_history(int argn, char** args)
{
  for (int i = 0; ; i++)
  {
    char* history = linenoiseHistoryLine(i);
    if (history == NULL) break;
    printf("%4d: %s", i, history);
    free(history);
  }
  return 0;
}

int cli_loop()
{
  while(1)
  {
    int argn;
    char* input = linenoise(prompt_prefix);
    char** args = parse(input, &argn);

    if (input == NULL)
    {
      break;
    }
    for (int i = 0; commands[i] != NULL; i++)
    {
      for (int j = 0; commands[i][j] != NULL; j++)
      {
        if (!strncmp(input, commands[i][j], strlen(commands[i][j])))
        {
          (*commandsCallback[i])(argn, args);
          goto ESCAPE_FOR_LOOP_0;
        }
      }
    }
    ESCAPE_FOR_LOOP_0:

    if (*input == '\0')
    {
      free(input);
      break;
    }

    linenoiseHistoryAdd(input);
    free(args);
    free(input);
  }

  return 0;
}

void completionHook(char const* prefix, linenoiseCompletions* lc)
{
  for (size_t i = 0; commands[i] != NULL; i++)
  {
    for (size_t j = 0; commands[i][j] != NULL; j++)
    {
      if (strncmp(prefix, commands[i][j], strlen(prefix)) == 0)
      {
        linenoiseAddCompletion(lc, commands[i][j]);
      }
    }
  }
}

int cli_init()
{
  linenoiseInstallWindowChangeHandler();

  const char* file = CLI_HISTORY_FILE;

  linenoiseHistoryLoad(file);
  linenoiseSetCompletionCallback(completionHook);

  cli_loop();
  
  linenoiseHistorySave(file);
  linenoiseHistoryFree();
  return 0;
}

char** parse(char* input, int* count)
{
  int length;
  char** args = NULL;
  char* token = strtok(input, " ");
  (*count) = 0;

  while (token != NULL)
  {
    (*count)++;
    args = (char**)realloc(args, (*count) * sizeof(char*));
    args[(*count) - 1] = token;
    token = strtok(NULL, " ");
  }

  args = (char**)realloc(args, (*count) * sizeof(char*));

  length = strlen(input);
  int n = 0;
  for (int i = 0; i < (*count); i++)
  {
    length -= strlen(args[i]) + strlen(" ");
    strncpy(args[i], input + n, strlen(args[i]));
    n += strlen(args[i]) + strlen(" ");
    args[i][strlen(args[i])] = '\0';
  }
  
  return args;
}
