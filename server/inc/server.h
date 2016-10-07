#pragma once

#include "tcpacceptor.h"
#include "tcpstream.h"

class Server
{
public:
	Server();
	Server(TCPAcceptor tcpAcceptor_);

	TCPStream Start(int family, int type, int protocol, int port) const;

	TCPStream Accept(const TCPStream& tcpStream) const;

private:
	TCPAcceptor tcpAcceptor;
};

