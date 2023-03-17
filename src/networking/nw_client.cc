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

#include "cppserver/asio/service.h"
#include "cppserver/asio/tcp_client.h"

#include <atomic>

class NetworkingClient : public CppServer::Asio::TCPClient
{
public:
	NetworkingClient(std::shared_ptr<CppServer::Asio::Service> service, const std::string& address, int port)
		: CppServer::Asio::TCPClient(service, address, port)
	{
		_stop = false;
	}

protected:
	void onCreated() override
	{

	}

private:
	std::atomic<bool> _stop;
};