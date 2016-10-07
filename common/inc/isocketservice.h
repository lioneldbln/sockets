#pragma once

#include <string>

#include "socket.h"

class ISocketService
{
public:
	virtual Socket CreateSocket(int family, int type, int protocol) = 0;
	virtual int Send(const Socket& socket, const std::string& strBuf) const = 0;
	virtual int Receive(const Socket& socket, std::string& strBuf) const = 0;
	virtual int Connect(const Socket& socket, int port, const std::string& ipAddress) const = 0;
	virtual int Bind(const Socket& socket, int port) const = 0;
	virtual int Listen(const Socket& socket) const = 0;
	virtual Socket Accept(const Socket& socket) const = 0;
};

class SocketService : public ISocketService
{
public:
	Socket CreateSocket(int family, int type, int protocol);
	int Send(const Socket& socket, const std::string& strBuf) const;
	int Receive(const Socket& socket, std::string& strBuf) const;
	int Connect(const Socket& socket, int port, const std::string& ipAddress) const;
	int Bind(const Socket& socket, int port) const;
	int Listen(const Socket& socket) const;
	Socket Accept(const Socket& socket) const;
};

class SocketServiceStub : public ISocketService
{
public:
	Socket CreateSocket(int family, int type, int protocol);
	int Send(const Socket& socket, const std::string& strBuf) const;
	int Receive(const Socket& socket, std::string& strBuf) const;
	int Connect(const Socket& socket, int port, const std::string& ipAddress) const;
	int Bind(const Socket& socket, int port) const;
	int Listen(const Socket& socket) const;
	Socket Accept(const Socket& socket) const;
};
