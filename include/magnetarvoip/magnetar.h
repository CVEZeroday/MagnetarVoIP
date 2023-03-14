#pragma once
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
#pragma comment(lib, "cppserver.lib")
#pragma comment(lib, "opus.lib")
#pragma comment(lib, "windowsapp")
#else
#ifdef __GNUC__
// Linux and MacOS are not supported in the initial version of MagnetarVoIP
#endif
#endif

#include "settings.h"
#include "macros.h"