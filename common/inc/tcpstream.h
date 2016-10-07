#pragma once

#include <string>
#include <memory>
#include <utility>

#include "socket.h"
#include "isocketservice.h"

class TCPStream
{
public:
	using t_SocketService = std::unique_ptr<ISocketService>;

	TCPStream();
	TCPStream(int port_, const std::string& ipAddress_);
	TCPStream(int port_, const std::string& ipAddress_, Socket socket_);
	TCPStream(int port_, const std::string& ipAddress_, t_SocketService socketService_);
	TCPStream(int port_, const std::string& ipAddress_, Socket socket_, t_SocketService socketService_);
	~TCPStream() = default;

	TCPStream(const TCPStream& x) = delete;
	TCPStream& operator=(const TCPStream& x) = delete;

	friend void swap(TCPStream& first, TCPStream& second) {
		using std::swap;
		swap(first.port, second.port);
		swap(first.ipAddress, second.ipAddress);
		swap(first.socket, second.socket);
		swap(first.socketService, second.socketService);
	}

	TCPStream(TCPStream&& x) : TCPStream{} {
		swap(*this, x);
	}
	TCPStream& operator=(TCPStream&& x) {
		swap(*this, x);
		return *this;
	}

	void Send(const std::string& mess) const;

	std::string Receive() const; 

	int GetPort() const {
		return port;
	}

	std::string GetIpAddress() const {
		return ipAddress;
	}

	const Socket& GetSocket() const {
		return socket;
	}

private:
	int port;
   std::string ipAddress;
	Socket socket;
	t_SocketService socketService;
};
