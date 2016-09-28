#include <string.h>
#include <errno.h>

#include "socket.h"

#include "exceptionex.h"

Socket::Socket(int socket_family, int socket_type, int protocol) : fd(-1)
{
   fd = socket(socket_family, socket_type, protocol);
	if(fd == -1)
		throw socket_failure(strerror(errno));
}

Socket::~Socket()
{
	close(fd);
}
