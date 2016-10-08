#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API
#include <unistd.h>
#include <system_error>	
#include <chrono>
#include <mutex>
#include <fstream>

#include "app.h"

#include "server.h"
#include "exceptionex.h"
#include "threadguard.h"
#include "quitfile.h"

std::mutex mtx;

void Receive(TCPStream newTcpStream)
{
	std::string strBuf = newTcpStream.Receive();
	//std::this_thread::sleep_for(std::chrono::seconds(strBuf.length()));
	unsigned int i = 0;
	while(i < strBuf.length()*100000000) i++;
	std::cout << strBuf << std::endl;
	newTcpStream.Send("OK from server");

	if(strBuf == "quit")
	{
		std::lock_guard<std::mutex> lx(mtx);
		QuitFile file;
	}
}

void App::Run() const
{
	std::cout << "Server started!" << std::endl;

	try
	{
		Server server;
		TCPStream tcpStream = server.Start(AF_INET, SOCK_STREAM, 0, 8080);
		while(1)
		{
			TCPStream newTcpStream = server.Accept(tcpStream);
			// --> Here, I'm going to create threads to manage multiple socket connections
			ThreadGuard thread(std::move(std::thread(Receive, std::move(newTcpStream))));

			std::ifstream quitFile("quit.txt");
			if (quitFile.is_open())
				break;
		}		
	}
	catch(std::logic_error& e)
	{
		std::cout << "MyException: " << e.what() << std::endl;
	}
	catch(const std::system_error& e)
	{
		std::cout << "std::system_error: " << e.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "UNEXEPECTED ERROR" << std::endl;
	}

	std::cout << "Server closed" << std::endl;
}
