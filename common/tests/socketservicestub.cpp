#include "isocketservice.h"

#include "socket.h"

Socket SocketServiceStub::CreateSocket(int family, int type, int protocol)
{
	if(family == -1 || type == -1 || protocol == -1)
		return Socket{};
	else
		return Socket(0);
}

int SocketServiceStub::Send(const Socket& socket, const std::string& strBuf) const
{
	if(socket.GetFileDescriptor() == -1)
		return -1;
	else
		return 0;
}

int SocketServiceStub::Receive(const Socket& socket, std::string& strBuf) const
{
	if(socket.GetFileDescriptor() == -1)
		return -1;
	else
		return 0;
}

int SocketServiceStub::Connect(const Socket& socket, int port, const std::string& ipAddress) const
{
	if(socket.GetFileDescriptor() == -1)
		return -1;
	else
		return 0;
}

int SocketServiceStub::Bind(const Socket& socket, int port) const
{
	if(socket.GetFileDescriptor() == -1)
		return -1;
	else
		return 0;
}

int SocketServiceStub::Listen(const Socket& socket) const
{
	if(socket.GetFileDescriptor() == -1)
		return -1;
	else
		return 0;
}

Socket SocketServiceStub::Accept(const Socket& socket) const
{
	if(socket.GetFileDescriptor() == -1)
		return Socket{};
	else
		return Socket(0);	
}
