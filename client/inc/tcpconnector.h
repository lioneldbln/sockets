#pragma once

#include <memory.h>
#include <utility>

#include "tcpstream.h"
#include "isocketservice.h"

class TCPConnector
{
public:
	using t_SocketService = std::unique_ptr<ISocketService>;

	TCPConnector();
	TCPConnector(t_SocketService socketService_);
	~TCPConnector() = default;

	TCPConnector(const TCPStream& x) = delete;
	TCPConnector& operator=(const TCPStream& x) = delete;

	friend void swap(TCPConnector& first, TCPConnector& second) {
		using std::swap;
		swap(first.socketService, second.socketService);
	}

	TCPConnector(TCPConnector&& x) : TCPConnector() {
		swap(*this, x);
	}
	TCPConnector& operator=(TCPConnector&& x) {
		swap(*this, x);
		return *this;
	}

	TCPStream Connect(int family, int type, int protocol, int port, const std::string& ipAddress);

private:
	t_SocketService socketService;
};
