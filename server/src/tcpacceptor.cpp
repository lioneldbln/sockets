#include <cstring>

#include "tcpacceptor.h"

#include "exceptionex.h"

TCPAcceptor::TCPAcceptor() : socketService{}
{
}

TCPAcceptor::TCPAcceptor(t_SocketService socketService_) : socketService(std::move(socketService_))
{
}

TCPStream TCPAcceptor::Start(int family, int type, int protocol, int port) const
{
	Socket socket = socketService->CreateSocket(family, type, protocol);
	if(socketService->Bind(socket, port) == -1)
		throw bind_failure(std::strerror(errno));

	if(socketService->Listen(socket) == -1)
		throw listen_failure(std::strerror(errno));

	return TCPStream(port, "", std::move(socket));
}

TCPStream TCPAcceptor::Accept(const TCPStream& tcpstream) const
{
	Socket socket = socketService->Accept(tcpstream.GetSocket());
	if(socket.GetFileDescriptor() == -1)
		throw accept_failure(std::strerror(errno));
	return TCPStream(0, "1", std::move(socket));
}
