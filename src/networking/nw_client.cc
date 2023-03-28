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
#include "threads/thread.h"

#include "nw.h"

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
	void onConnected() override
	{
		//onConnected
	}
	
	void onDisconnected() override
	{

		CppCommon::Thread::Sleep(100);
		if (!_stop)
			ConnectAsync();
	}

	void onReceived(const void* buffer, size_t size) override
	{
		packetReceivedHandler(buffer, size);
	}

	void onError(int error, const std::string& category, const std::string& message) override
	{

	}

private:
	std::atomic<bool> _stop;
};
