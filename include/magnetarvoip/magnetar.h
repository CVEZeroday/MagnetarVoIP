#ifndef __MAGNETAR_H__
#define __MAGNETAR_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*         File Name: magnetar.h            */
/*   Created by CVE_zeroday on 15.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#ifdef _MSC_VER
#pragma comment(lib, "asio.lib")
#pragma comment(lib, "cppbenchmark.lib")
#pragma comment(lib, "cpp-optparse.lib")
#pragma comment(lib, "windowsapp")
#pragma comment(lib, "cppserver.lib")
#else
#endif

#include "settings.h"
#include "macros.h"

extern int32_t error_type;

#endif
