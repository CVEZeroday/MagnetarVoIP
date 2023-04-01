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

#include "cppserver/asio/tcp_server.h"
#include "threads/thread.h"
#include "nw.h"

#include <atomic>

class NetworkingSession : public CppServer::Asio::TCPSession
{
public:
	using CppServer::Asio::TCPSession::TCPSession;
protected:
	void onConnected() override
	{
		//onConnected
	}
	
	void onDisconnected() override
	{
		//onDisconnected
	}

	void onReceived(const void* buffer, size_t size) override
	{
		//onReceived
	}

	void onError(int error, const std::string& category, const std::string& message) override
	{
		printf("Error ocurred: error code %d, %s: %s\n", error, category.c_str(), message.c_str());
	}
};

class NetworkingServer : public CppServer::Asio::TCPServer
{
public:
	using CppServer::Asio::TCPServer::TCPServer;

protected:
	std::shared_ptr<CppServer::Asio::TCPSession> CreateSession(const std::shared_ptr<CppServer::Asio::TCPServer>& server) override
	{
		return std::make_shared<NetworkingSession>(server);
	}

	void onError(int error, const std::string& category, const std::string& message) override
	{
		printf("Error ocurred: error code %d, %s: %s\n", error, category.c_str(), message.c_str());
	}
};