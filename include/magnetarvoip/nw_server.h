#ifndef __NW_SERVER_HPP__
#define __NW_SERVER_HPP__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_server.hpp          */
/*   Created by CVE_zeroday on 15.04.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
/* THIS FILE CANNOT BE INCLUDED IN .c FILES */

#include "nw.h"

// Function Definition
int32_t init_nwserver();
int32_t send_nwserver(const void* buffer, size_t size);

#endif
