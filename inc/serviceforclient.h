#pragma once

#include "service.h"

class ServiceForClient : public Service
{
	int Connect(const Socket& socket) override;
	int Send(const Socket& socket, const std::string& mess) override;
};
