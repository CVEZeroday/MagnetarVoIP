#ifndef __CMD_H__
#define __CMD_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*            File Name: cmd.h              */
/*   Created by CVE_zeroday on 04.06.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

#include <stdlib.h>

#include "macros.h"

int32_t cmd_callback_chatting(char* input);
int32_t cmd_callback_nocommand(int32_t argn, char** args);
int32_t cmd_callback_connect(int32_t argn, char** args);
int32_t cmd_callback_disconnect(int32_t argn, char** args);
int32_t cmd_callback_setting(int32_t argn, char** args);
int32_t cmd_callback_volumeup(int32_t argn, char** args);
int32_t cmd_callback_volumedown(int32_t argn, char** args);
int32_t cmd_callback_volumesetting(int32_t argn, char** args);
int32_t cmd_callback_inputup(int32_t argn, char** args);
int32_t cmd_callback_inputdown(int32_t argn, char** args);
int32_t cmd_callback_inputsetting(int32_t argn, char** args);
int32_t cmd_callback_mute(int32_t argn, char** args);
int32_t cmd_callback_help(int32_t argn, char** args);
int32_t cmd_callback_info(int32_t argn, char** args);
int32_t cmd_callback_exit(int32_t argn, char** args);

static const char* commands[][4] = {
  {"/connect", "/c", "/con"},
  {"/disconnect", "/dc", "/dcon"},
  {"/setting", "/s"},
  {"/volumeup", "/vu", "/volup"},
  {"/volumedown", "/vd", "/voldown"},
  {"/volumesetting", "/vs", "/volset"},
  {"/inputup", "/iu", "/inup"},
  {"/inputdown", "/id", "/indown"},
  {"/inputsetting", "/is", "/inset"},
  {"/mute", "/m"},
  {"/help", "/h", "/?"},
  {"/info", "/i"},
  {"/exit", "/quit"}
};

static const char* description_en[] = {
  "/connect, /c, /con : Connect to the server.\n",
  "/disconnect, /dc, /dcon : Disconnect from the server.\n",
  "/setting, /s : Change terminal to setting mode.\n",
  "/volumeup, /vu, /volup : Increase the volume.\nusage: /volumeup <amount>, default is 1\n",
  "/volumedown, /vd, /voldown : Decrease the volume.\nusage: /volumedown <amount>, default is 1\n",
  "/volumesetting, /vs, /volset : Change terminal to volume setting mode.\n",
  "/inputup, /iu, /inup : Increase the input volume of your microphone\nusage: /inputup <amount>, default is 1\n",
  "/inputdown, /id, /indown : Decrease the input volume of your microphone.\nusage: /inputdown <amount>, default is 1\n",
  "/inputsetting, /is, /inset : Change terminal to volume setting mode.\n",
  "/mute, /m : Mute your microphone.\n",
  "/help, /h : Print32_t the list or description of the specific command.\nusage: /help <commands>\n",
  "/info, /i : Print32_t the information about MagnetarVoIP.\n",
  "/exit, /quit : Exit the program.\n"
};

static const char* description_ko[] = {
  "/connect, /c, /con : 서버와 연결합니다.\n",
  "/disconnect, /dc, /dcon : 서버와 연결을 종료합니다.\n",
  "/setting, /s : 설정 모드에 진입합니다.\n",
  "/volumeup, /vu, /volup : 사운드 볼륨을 높입니다.\n사용법: /volumeup <amount>, 기본값 1\n",
  "/volumedown, /vd, /voldown : 사운드 볼륨을 낮춥니다.\n사용법: /volumedown <amount>, 기본값 1\n",
  "/volumesetting, /vs, /volset : 볼륨 설정 모드에 진입합니다.\n",
  "/inputup, /iu, /inup : 마이크 입력 볼륨을 높입니다.\n사용법: /inputup <amount>, 기본값 1\n",
  "/inputdown, /id, /indown : 마이크 입력 볼륨을 낮춥니다.\n사용법: /inputdown <amount>, 기본값 1\n",
  "/inputsetting, /is, /inset : 마이크 입력 설정 모드에 진입합니다.\n",
  "/mute, /m : 마이크를 음소거합니다.\n",
  "/help, /h : 명령어의 종류 혹은 특정 명령어에 대한 설명을 출력합니다.\n사용법: /help <commands>\n",
  "/info, /i : MagnetarVoIP에 대한 정보를 출력합니다.\n",
  "/exit, /quit : 프로그램을 종료합니다.\n"
};

static int32_t (*commandsCallback[])(int32_t argn, char** args) = {
  cmd_callback_connect,
  cmd_callback_disconnect,
  cmd_callback_setting,
  cmd_callback_volumeup,
  cmd_callback_volumedown,
  cmd_callback_volumesetting,
  cmd_callback_inputup,
  cmd_callback_inputdown,
  cmd_callback_inputsetting,
  cmd_callback_mute,
  cmd_callback_help,
  cmd_callback_info,
  cmd_callback_exit
};

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
