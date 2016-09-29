#include <iostream>
#include <memory>

#include "client.h"
#include "exceptionex.h"
#include "clientservice.h"

int main(int argc, char* argv[])
{
   std::cout << "Hello World!" << std::endl;

	std::cout << "Client started!" << std::endl;

	try
	{
		Client client(std::move(Socket(AF_INET, SOCK_STREAM, 0)), std::move(std::unique_ptr<IClientService>{new ClientService()}));
		client.Connect();
		client.Send("Hello World!");
	}
	catch(std::logic_error& e)
	{
		std::cout << "MyException: " << e.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "UNEXEPECTED ERROR" << std::endl;
	}


	std::cout << "Client closed" << std::endl;

   return 0;
}
