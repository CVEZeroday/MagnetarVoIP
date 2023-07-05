#ifndef __INIT_NETWORK_H__
#define __INIT_NETWORK_H__
/********************************************/
/* This header file is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: init_network.h         */
/*   Created by CVE_zeroday on 15.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "macros.h"

int32_t init_network();
//int init_networkingServer(std::shared_ptr<CppServer::Asio::Service> service);
//int init_networkingClient(std::shared_ptr<CppServer::Asio::Service> service);
uint8_t init_rtp();

#endif
