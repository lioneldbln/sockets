#pragma once

#include <memory>

#include "tcpstream.h"
#include "tcpconnector.h"

class Client
{
public:
	Client();
	Client(TCPConnector tcpConnector_);
   ~Client() = default;

   Client(const Client& x) = delete;
   Client& operator=(const Client& x) = delete;

	Client(Client&& x) = delete;
	Client& operator=(Client&& x) = delete;

	TCPStream Connect(int family, int type, int protocol, int port, const std::string& ipAddress);

private:
	TCPConnector tcpConnector;
};
