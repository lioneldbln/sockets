#include <cstring>

#include "tcpconnector.h"

#include "exceptionex.h"

TCPConnector::TCPConnector() : socketService{}
{
}

TCPConnector::TCPConnector(t_SocketService socketService_) : socketService(std::move(socketService_))
{
}

TCPStream TCPConnector::Connect(int family, int type, int protocol, int port, const std::string& ipAddress)
{
	Socket socket = socketService->CreateSocket(family, type, protocol);
	if(socketService->Connect(socket, port, ipAddress) == -1)
		throw connection_failure(std::strerror(errno));
	return TCPStream(port, ipAddress, std::move(socket));
}
