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
#include "macros.h"

#include <atomic>

// Variable Definition

std::shared_ptr<CppServer::Asio::Service> service_client;
std::shared_ptr<NetworkingClient> client;

int32_t init_nwclient()
{
  // NetworkingClient Class Instantiate
  service_client = std::make_shared<CppServer::Asio::Service>();
  service_client->Start();

  client = std::make_shared<NetworkingClient>(service_client, Address, Port);
  client->ConnectAsync();

  return 0;
}

int32_t send_nwclient(const void* buffer, size_t size)
{
  //DEBUG_PRINTF("sendnwclient: buffer: %s", ((const NW_PACKET*)buffer)->data.chat.str);
  client->SendAsync(buffer, size);

  return 0;
}

int32_t close_nwclient()
{
  client->DisconnectAndStop();
  service_client->Stop();

  return 0;
}
