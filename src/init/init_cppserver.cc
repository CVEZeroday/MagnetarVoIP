/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*      File Name: init_cppserver.cc        */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <cppserver/asio/tcp_server.h>
#include <cppserver/asio/asio.h>

#include "init_cppserver.h"
#include "nw.h"
#include "macros.h"
#include "settings.h"

int init_cppserver()
{
	auto service = std::make_shared<CppServer::Asio::Service>();
	service->Start();

	auto server = std::make_shared<NetworkingServer>(service, Port);
	server->Start();
	Initialized |= NETWORK_FLAG;
	return 0;
}
