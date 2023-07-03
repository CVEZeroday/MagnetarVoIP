#ifndef __NW_CLIENT_HPP__
#define __NW_CLIENT_HPP__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_client.hpp          */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.hpp"

// Function Definition

int32_t init_nwclient();
int32_t send_nwclient(const void* buffer, size_t size);

#endif
