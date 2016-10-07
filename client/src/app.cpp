#include <iostream>
#include <memory>
#include <unistd.h>
#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API

#include "app.h"

#include "client.h"
#include "exceptionex.h"

void App::Run()
{
   std::cout << "Client started!" << std::endl;

	try
	{
		Client client;

		while(1)
		{
			std::string input;
			getline(std::cin, input);

			client.Connect(AF_INET, SOCK_STREAM, 0, 8080, "127.0.0.1").Send(input);

			if(input == "quit")
				break;
		}		
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
}

