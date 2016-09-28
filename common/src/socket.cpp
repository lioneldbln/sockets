#include <string.h>
#include <errno.h>

#include "socket.h"

#include "exceptionex.h"

int Socket::cnt = 0;

Socket::Socket(int socket_family, int socket_type, int protocol) : fd(-1)
{
   fd = socket(socket_family, socket_type, protocol);
	if(fd == -1)
		throw socket_failure(strerror(errno));
   cnt++;
}

Socket::~Socket()
{
   CloseSocket();
}

void Socket::CloseSocket()
{
	if(fd != -1)
	{
   	if(close(fd) != -1)
      	cnt--;
	}
}
