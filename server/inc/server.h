#pragma once

#include <memory>

#include "socket.h"
#include "iserverservice.h"

class Server
{
public:
	Server(Socket s_, std::unique_ptr<IServerService> sfs_);

	void Bind();

	void Listen();

	Socket Accept();

	void Receive(const Socket& socket);

private:
	Socket socket;
	std::unique_ptr<IServerService> serv;
};

