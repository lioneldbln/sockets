#include <cstring>

#include "server.h"

Server::Server() : Server(std::move(TCPAcceptor(std::move(TCPAcceptor::t_SocketService(new SocketService)))))
{
}

Server::Server(TCPAcceptor tcpAcceptor_) : tcpAcceptor(std::move(tcpAcceptor_))
{
}

TCPStream Server::Start(int family, int type, int protocol, int port) const
{
	return tcpAcceptor.Start(family, type, protocol, port);
}

TCPStream Server::Accept(const TCPStream& tcpStream) const
{
	return tcpAcceptor.Accept(tcpStream);
}
