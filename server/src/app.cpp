#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API

#include "app.h"

#include "server.h"
#include "exceptionex.h"

void App::Run()
{
	std::cout << "Server started!" << std::endl;

	try
	{
		Server server;
		TCPStream tcpStream = server.Start(AF_INET, SOCK_STREAM, 0, 8080);
		while(1)
		{
			TCPStream newTcpStream = server.Accept(tcpStream);
			std::string strBuf = newTcpStream.Receive();
			std::cout << strBuf << std::endl;

			if(strBuf == "quit")
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

	std::cout << "Server closed" << std::endl;
}
