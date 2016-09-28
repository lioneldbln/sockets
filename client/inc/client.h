#pragma once

#include <memory>

#include "socket.h"
#include "iclientservice.h"

class Client
{
public:
	Client(Socket s_, std::unique_ptr<IClientService> sfc_);
   ~Client() = default;

   Client(const Client& x) = delete;
   Client& operator=(const Client& x) = delete;

	Client(Client&& x) = delete;
	Client& operator=(Client&& x) = delete;

	void Connect();

   void Send(const std::string& mess);

private:
   Socket socket;
   std::unique_ptr<IClientService> serv;
};
