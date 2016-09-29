#pragma once

#include "iserverservice.h"

class ServerService : public IServerService
{
public:
	int Bind(const Socket& socket) override;

	int Listen(const Socket& socket) override;

	Socket Accept(const Socket& socket) override;

	int Receive(const Socket& socket) override;
};
