#include <string.h>

#include "client.h"

Client::Client() : Client(std::move(TCPConnector(std::move(TCPConnector::t_SocketService(new SocketService)))))
{
}

Client::Client(TCPConnector tcpConnector_) : tcpConnector(std::move(tcpConnector_))
{
}

TCPStream Client::Connect(int family, int type, int protocol, int port, const std::string& ipAddress)
{	
	return tcpConnector.Connect(family, type, protocol, port, ipAddress);
}
