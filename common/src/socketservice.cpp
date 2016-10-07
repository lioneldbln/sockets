#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "isocketservice.h"

#include "socket.h"

Socket SocketService::CreateSocket(int family, int type, int protocol)
{
	return Socket(family, type, protocol);
}

int SocketService::Send(const Socket& socket, const std::string& strBuf) const
{
	const char* c_ = strBuf.c_str();
   int size = strlen(c_)+1;
	return send(socket.GetFileDescriptor(), c_, size, 0);
}

int SocketService::Receive(const Socket& socket, std::string& strBuf) const
{
	char buf[512];
	int rc = recv(socket.GetFileDescriptor(), buf, 512, 0);
	if(rc != -1)
	{
		buf[rc]= (char) NULL; // Null terminate string
		strBuf = buf;
	}
	return rc;
}

int SocketService::Connect(const Socket& socket, int port, const std::string& ipAddress) const
{
	struct sockaddr_in socketInfo;
	socketInfo.sin_family = AF_INET;
	socketInfo.sin_port = htons(port);
	inet_aton(ipAddress.c_str(), &socketInfo.sin_addr);
   memset(socketInfo.sin_zero, '\0', sizeof(socketInfo.sin_zero));
	return connect(socket.GetFileDescriptor(), (struct sockaddr *)&socketInfo, sizeof(sockaddr_in));
}

int SocketService::Bind(const Socket& socket, int port) const
{
	struct sockaddr_in socketInfo;
	bzero(&socketInfo, sizeof(sockaddr_in));  // Clear structure memory
	socketInfo.sin_family = PF_INET;
	socketInfo.sin_addr.s_addr = htonl(INADDR_ANY); // Use any address available to the system
	socketInfo.sin_port = htons(port);      // Set port number
	return bind(socket.GetFileDescriptor(), (struct sockaddr *) &socketInfo, sizeof(socketInfo));
}

int SocketService::Listen(const Socket& socket) const
{
	return listen(socket.GetFileDescriptor(), 1);
}

Socket SocketService::Accept(const Socket& socket) const
{
	return Socket(accept(socket.GetFileDescriptor(), NULL, NULL));
}
