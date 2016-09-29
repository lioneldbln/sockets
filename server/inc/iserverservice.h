#pragma once

#include "socket.h"

class IServerService
{
public:
	virtual int Bind(const Socket& socket) = 0;

	virtual int Listen(const Socket& socket) = 0;

   virtual Socket Accept(const Socket& socket) = 0;

	virtual int Receive(const Socket& socket) = 0;
};
