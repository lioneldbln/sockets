#pragma once

#include "iclientservice.h"

class ClientService : public IClientService
{
public:
	int Connect(const Socket& socket) override;
	int Send(const Socket& socket, const std::string& mess) override;
};
