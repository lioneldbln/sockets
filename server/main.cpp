#include <iostream>
#include <memory>

#include "server.h"
#include "exceptionex.h"
#include "serverservice.h"

int main(int argc, char* argv[])
{
	std::cout << "Server started!" << std::endl;

	try
	{
		Server server(std::move(Socket(AF_INET, SOCK_STREAM, 0)), std::move(std::unique_ptr<IServerService>{new ServerService()}));
		server.Bind();
		server.Listen();
		Socket newsocket = server.Accept();
		server.Receive(newsocket);
	}
	catch(std::logic_error& e)
	{
		std::cout << "MyException: " << e.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "UNEXEPECTED ERROR" << std::endl;
	}


	std::cout << "Server closed" << std::endl;

	return 0;
}
