#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API

#include "socket.h"

#include "exceptionex.h"

#include <iostream>

Socket::Socket(int fd_) : fd(fd_)
{
	std::cout << "Create socket:" << fd << std::endl;
}

Socket::Socket(int socket_family, int socket_type, int protocol)
{
   fd = socket(socket_family, socket_type, protocol);
	if(fd == -1)
		throw socket_failure(strerror(errno));
   int optval = 1;
   int optlen = sizeof(optval);
   if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, optlen) == -1)
		throw socket_failure(strerror(errno));
	std::cout << "Create socket:" << fd << std::endl;
}

Socket::~Socket()
{
	if(fd!=-1)
	{
		std::cout << "Close socket:" << fd << std::endl;
		close(fd);
	}
}
