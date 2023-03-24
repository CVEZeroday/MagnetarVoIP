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
#include "nw.h"

#include <atomic>

class NetworkingSession : public CppServer::Asio::TCPSession
{
protected:
	void onConnected() override
	{
		
	}
};