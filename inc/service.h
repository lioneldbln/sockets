#pragma once

#include <string>

#include "socket.h"

class Service
{
public:
	virtual int Connect(const Socket& socket) = 0;
	virtual int Send(const Socket& socket, const std::string& mess) = 0;
};

