#include <string.h>

#include "server.h"

#include "exceptionex.h"

Server::Server(Socket s_, std::unique_ptr<IServerService> sfs_) : socket(std::move(s_)), serv(std::move(sfs_))
{
}

void Server::Bind()
{
	if(serv->Bind(socket) == -1)
		throw bind_failure(strerror(errno));
}

void Server::Listen()
{
	if(serv->Listen(socket) == -1)
		throw listen_failure(strerror(errno));
}

Socket Server::Accept()
{
   Socket newsocket = serv->Accept(socket);
	if(socket.GetFileDescriptor() == -1)
		throw accept_failure(strerror(errno));
	return newsocket;
}

void Server::Receive(const Socket& socket)
{
	if(serv->Receive(socket) == -1)
		throw receive_failure(strerror(errno));
}
