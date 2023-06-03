#ifndef __NW_SERVER_HPP__
#define __NW_SERVER_HPP__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*        File Name: nw_server.hpp          */
/*   Created by CVE_zeroday on 15.04.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
/* THIS FILE CANNOT BE INCLUDED IN .c FILES */

#include "cppserver/asio/tcp_server.h"
#include "threads/thread.h"

#include <atomic>

// Function Definition
int init_nwserver();

// Class Definition

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


#endif