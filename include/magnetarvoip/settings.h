#ifndef __SETTINGS_H__
#define __SETTINGS_H__
/********************************************/
/* This header file is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: settings.h            */
/*   Created by CVE_zeroday on 15.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

enum PROGRAM_MODE {
	CLI_MODE,
	GUI_MODE,
	TUI_MODE
};
int ProgramMode = CLI_MODE;

#endif