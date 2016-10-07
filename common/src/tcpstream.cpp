#include <cstring>
#include <unistd.h>
#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API
#include "tcpstream.h"

#include "exceptionex.h"

TCPStream::TCPStream()
	: port{}, ipAddress{}, socket{}, socketService{}
{
}

TCPStream::TCPStream(int port_, const std::string& ipAddress_)
	: TCPStream(port_, ipAddress_, std::move(Socket(AF_INET, SOCK_STREAM, 0)), std::move(t_SocketService(new SocketService)))
{
}

TCPStream::TCPStream(int port_, const std::string& ipAddress_, Socket socket_)
	: TCPStream(port_, ipAddress_, std::move(socket_), std::move(t_SocketService(new SocketService)))
{
}

TCPStream::TCPStream(int port_, const std::string& ipAddress_, t_SocketService socketService_)
	: TCPStream(port_, ipAddress_, std::move(Socket(AF_INET, SOCK_STREAM, 0)), std::move(socketService_))
{
}

TCPStream::TCPStream(int port_, const std::string& ipAddress_, Socket socket_, t_SocketService socketService_)
	: port(port_), ipAddress(ipAddress_), socket(std::move(socket_)), socketService(std::move(socketService_))
{
}

void TCPStream::Send(const std::string& strBuf) const
{
	if(socketService->Send(socket, strBuf) == -1)
		throw send_failure(std::strerror(errno));
}

std::string TCPStream::Receive() const
{ 
	std::string strBuf;
	if(socketService->Receive(socket, strBuf) == -1)
		throw receive_failure(std::strerror(errno));
	return strBuf;
}
