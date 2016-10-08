#include <iostream>
#include <memory>
#include <unistd.h>
#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API

#include "app.h"

#include "client.h"
#include "exceptionex.h"

void App::Run() const
{
   std::cout << "Client started!" << std::endl;

	try
	{
		Client client;

		while(1)
		{
			std::string input = GetLineFromConsole();

			TCPStream tcpStream = client.Connect(AF_INET, SOCK_STREAM, 0, 8080, "127.0.0.1");
			tcpStream.Send(input);
			std::string strBuf = tcpStream.Receive();
			std::cout << strBuf << std::endl;

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

std::string App::GetLineFromConsole() const
{
	std::string input;
	getline(std::cin, input);
	return input;
}
