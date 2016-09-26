#pragma once

#include <memory>

#include "socket.h"
#include "service.h"

class Client
{
public:
	Client(Socket s_, std::unique_ptr<Service> sfc_);

	void Connect();

   void Send(const std::string& mess);

private:
   Socket socket;
   std::unique_ptr<Service> serv;
};
