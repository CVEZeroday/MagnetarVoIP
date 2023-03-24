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

#include "cppserver/asio/tcp_client.h"
#include "nw.h"

#include <atomic>

class NetworkingClient : public CppServer::Asio::TCPClient
{
public:
	NetworkingClient(std::shared_ptr<CppServer::Asio::Service> service, const std::string& address, int port)
		: CppServer::Asio::TCPClient(service, address, port)
	{
		_stop = false;
		SetupNoDelay(true);
	}

	void DisconnectAndStop()
	{
		_stop = true;
		DisconnectAsync();
		while (IsConnected())
			CppCommon::Thread::Yield();
	}

protected:
	void onConnected() override
	{
		printf("Connected!\n");
	}
	
	void onDisconnected() override
	{
		printf("Disconnected.\n");
		CppCommon::Thread::Sleep(100);
		if (!_stop)
			ConnectAsync();
	}

	void onReceived(const void* buffer, size_t size) override
	{
		// onReceived는 여기서 바로 처리
	}

	void onError(int error, const std::string& category, const std::string& message) override
	{
		printf("Error ocurred: error code %d, %s: %s\n", error, category.c_str(), message.c_str());
	}

private:
	std::atomic<bool> _stop;
};