/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_client.cc           */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include "nw.hpp"
#include "nw_client.hpp"
#include "settings.h"

#include <atomic>

// Variable Definition

std::shared_ptr<CppServer::Asio::Service> service;
std::shared_ptr<NetworkingClient> client;

int init_nwclient()
{
  // NetworkingClient Class Instantiate
  service = std::make_shared<CppServer::Asio::Service>();
  service->Start();

  client = std::make_shared<NetworkingClient>(service, Address, Port);
  client->ConnectAsync();

  return 0;
}

int close_nwclient()
{
  client->DisconnectAndStop();
  service->Stop();

  return 0;
}
