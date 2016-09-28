#include <string.h>

#include "client.h"

#include "exceptionex.h"

Client::Client(Socket s_, std::unique_ptr<IClientService> sfc_) : socket(std::move(s_)), serv(std::move(sfc_))
{
}

void Client::Connect()
{
	if(serv->Connect(socket) == -1)
		throw connection_failure(strerror(errno));
}

void Client::Send(const std::string& mess)
{
	if(serv->Send(socket, mess) == -1)
		throw send_failure(strerror(errno));
}
