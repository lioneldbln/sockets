#pragma once

#include <memory>

#include "isocketservice.h"
#include "tcpstream.h"

class TCPAcceptor
{
public:
	using t_SocketService = std::unique_ptr<ISocketService>;

	TCPAcceptor();
	TCPAcceptor(t_SocketService socketService_);
	~TCPAcceptor() = default;

	TCPAcceptor(const TCPAcceptor& x) = delete;
	TCPAcceptor& operator=(const TCPAcceptor& x) = delete;

	friend void swap(TCPAcceptor& first, TCPAcceptor& second) {
		using std::swap;
		std::swap(first.socketService, second.socketService);
	}

	TCPAcceptor(TCPAcceptor&& x) : TCPAcceptor{} {
		swap(*this, x);
	}
	TCPAcceptor& operator=(TCPAcceptor&& x) {
		swap(*this, x);
		return *this;
	}

	TCPStream Start(int family, int type, int protocol, int port) const;

	TCPStream Accept(const TCPStream& tcpstream) const;

private:
	t_SocketService socketService;
};
