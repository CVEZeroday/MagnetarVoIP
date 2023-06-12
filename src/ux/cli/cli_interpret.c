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

#include "linenoise/linenoise.h"

#include "cli.h"
#include "cht.h"
#include "cmd.h"
#include "macros.h"
#include "settings.h"
#include "core_thread.h"
#include "nw_interface.h"

int cmd_callback_chatting(char* input)
{
  send_chat(input);
  //DEBUG_PRINTF("Input: %s\n", input);

  return 0;
}

int cmd_callback_nocommand(int argn, char** args)
{
  DEBUG_PRINTF("No Command: %s\n", args[0]);
  return 0;
}

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
  DEBUG_PRINTF("History Callback\n");
  for (int i = 0; ; i++)
  {
    char* history = linenoiseHistoryLine(i);
    if (history == NULL) break;
    printf("%4d: %s\n", i, history);
    free(history);
  }
  return 0;
}

int cmd_callback_exit(int argn, char** args)
{
  changeProgramStatus(KILL);
  return 0;
}

inline int cli_loop()
{
  DEBUG_PRINTF("Entering CLI Loop\n");
  while(ProgramStatus != KILL)
  {
    char* input = linenoise(prompt_prefix);
    if (input == NULL)
    {
      break;
    }
    if (*input == '\0')
    {
      free(input);
      continue;
    }
    if (*input != '/' || *input == '\\')
    {
      cmd_callback_chatting(input);
      free(input);
      continue;
    }

    int argn, flag = 0;
    char** args = parse(input, &argn);

    if (args[0][0] == '/')
    {
      for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
      {
        for (int j = 0; commands[i][j] != NULL; j++)
        {
          if (strcmp(input, commands[i][j]) == 0)
          {
            (*commandsCallback[i])(argn, args);
            DEBUG_PRINTF("%s, %d, %d\n", args[0], i, j);
            flag = 1;
          }
          if (flag) break;
        }
        if (flag) break;
      }
      if(!flag) cmd_callback_nocommand(argn, args);
    }

    linenoiseHistoryAdd(input);
    free(args);
    free(input);
  }

  return 0;
}

void completionHook(char const* prefix, linenoiseCompletions* lc)
{
  for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
  {
    for (int j = 0; commands[i][j] != NULL; j++)
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

char** parse(char* input, int32_t* count)
{
  int length;
  char** args = NULL;
  char* _input = (char*)malloc(strlen(input));
  memcpy(_input, input, strlen(input));
  char* token = strtok(_input, " ");
  (*count) = 0;

  while (token != NULL)
  {
    (*count)++;
    args = (char**)realloc(args, (*count) * sizeof(char*));
    args[(*count) - 1] = token;
    token = strtok(NULL, " ");
  }

  args = (char**)realloc(args, (*count) * sizeof(char*));

  length = strlen(_input);
  int n = 0;
  for (int i = 0; i < (*count); i++)
  {
    length -= strlen(args[i]) + strlen(" ");
    strncpy(args[i], _input + n, strlen(args[i]));
    n += strlen(args[i]) + strlen(" ");
    args[i][strlen(args[i])] = '\0';
  }
  
  return args;
}
