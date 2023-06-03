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

int cmd_callback_connect(int argn, char** args);
int cmd_callback_disconnect(int argn, char** args);
int cmd_callback_setting(int argn, char** args);
int cmd_callback_volumeup(int argn, char** args);
int cmd_callback_volumedown(int argn, char** args);
int cmd_callback_volumesetting(int argn, char** args);
int cmd_callback_inputup(int argn, char** args);
int cmd_callback_inputdown(int argn, char** args);
int cmd_callback_inputsetting(int argn, char** args);
int cmd_callback_mute(int argn, char** args);
int cmd_callback_help(int argn, char** args);
int cmd_callback_info(int argn, char** args);
int cmd_callback_history(int argn, char** args);

static const char* commands[][4] = {
  {"/connect", "/c", "/con", NULL},
  {"/disconnect", "/dc", "/dcon", NULL},
  {"/setting", "/s", NULL},
  {"/volumeup", "/vu", "/volup", NULL},
  {"/volumedown", "/vd", "/voldown", NULL},
  {"/volumesetting", "/vs", "/volset", NULL},
  {"/inputup", "/iu", "/inup", NULL},
  {"/inputdown", "/id", "/indown", NULL},
  {"/inputsetting", "/is", "/inset", NULL},
  {"/mute", "/m", NULL},
  {"/help", "/h", "/?", NULL},
  {"/info", "/i", NULL},
  {"/history", "/hist", NULL},
  NULL
};

static const char* description_en[] = {
  "/connect, /c, /con : Connect to the server.",
  "/disconnect, /dc, /dcon : Disconnect from the server.",
  "/setting, /s : Change terminal to setting mode.",
  "/volumeup, /vu, /volup : Increase the volume.\nusage: /volumeup <amount>, default is 1",
  "/volumedown, /vd, /voldown : Decrease the volume.\nusage: /volumedown <amount>, default is 1",
  "/volumesetting, /vs, /volset : Change terminal to volume setting mode.",
  "/inputup, /iu, /inup : Increase the input volume of your microphone\nusage: /inputup <amount>, default is 1",
  "/inputdown, /id, /indown : Decrease the input volume of your microphone.\nusage: /inputdown <amount>, default is 1",
  "/inputsetting, /is, /inset : Change terminal to volume setting mode.",
  "/mute, /m : Mute your microphone.",
  "/help, /h : Print the list or description of the specific command.\nusage: /help <commands>",
  "/info, /i : Print the information about MagnetarVoIP.",
  "/history, /hist : Print your command history."
};

static const char* description_ko[] = {
  "/connect, /c, /con : 서버와 연결합니다.",
  "/disconnect, /dc, /dcon : 서버와 연결을 종료합니다.",
  "/setting, /s : 설정 모드에 진입합니다.",
  "/volumeup, /vu, /volup : 사운드 볼륨을 높입니다.\n사용법: /volumeup <amount>, 기본값 1",
  "/volumedown, /vd, /voldown : 사운드 볼륨을 낮춥니다.\n사용법: /volumedown <amount>, 기본값 1",
  "/volumesetting, /vs, /volset : 볼륨 설정 모드에 진입합니다.",
  "/inputup, /iu, /inup : 마이크 입력 볼륨을 높입니다.\n사용법: /inputup <amount>, 기본값 1",
  "/inputdown, /id, /indown : 마이크 입력 볼륨을 낮춥니다.\n사용법: /inputdown <amount>, 기본값 1",
  "/inputsetting, /is, /inset : 마이크 입력 설정 모드에 진입합니다.",
  "/mute, /m : 마이크를 음소거합니다.",
  "/help, /h : 명령어의 종류 혹은 특정 명령어에 대한 설명을 출력합니다.\n사용법: /help <commands>",
  "/info, /i : MagnetarVoIP에 대한 정보를 출력합니다.",
  "/history, /hist : 명령어 기록을 출력합니다."
};

static int (*commandsCallback[])(int argn, char** args) = {
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
  cmd_callback_history
};

/********************************************/
#ifdef __cplusplus
}
#endif
#endif
