/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_server.cc           */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.hpp"
#include "nw_server.hpp"
#include "settings.h"

#include <atomic>

// Variable Definition 

std::shared_ptr<CppServer::Asio::Service> service_server;
std::shared_ptr<NetworkingServer> server;

int init_nwserver()
{
  // NetworkingServer Class instantiate
  service_server = std::make_shared<CppServer::Asio::Service>();
  service_server->Start();

  server = std::make_shared<NetworkingServer>(service_server, Port);
  server->Start();

  return 0;
}

int close_nwserver()
{
  server->Stop();
  service_server->Stop();

  return 0;
}
