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

#include "init_cppserver.hpp"
#include "nw.hpp"
#include "nw_server.hpp"
#include "nw_client.hpp"

#include "macros.h"
#include "settings.h"

int init_cppserver()
{
	auto service = std::make_shared<CppServer::Asio::Service>();
	service->Start();

  if(IsServer)
    init_networkingServer(service);
  else
    init_networkingClient(service);

  Initialized |= NETWORK_FLAG;

	return 0;
}

int init_networkingServer(std::shared_ptr<CppServer::Asio::Service> service)
{
	auto server = std::make_shared<NetworkingServer>(service, Port);
	server->Start();

  return 0;
}

int init_networkingClient(std::shared_ptr<CppServer::Asio::Service> service)
{
  auto client = std::make_shared<NetworkingClient>(service, Address, Port);
  client->ConnectAsync();

  return 0;
}
