#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <strings.h>
#include <iostream>

#include "serverservice.h"

int ServerService::Bind(const Socket& socket)
{
	struct sockaddr_in socketInfo;
	bzero(&socketInfo, sizeof(sockaddr_in));  // Clear structure memory
	socketInfo.sin_family = PF_INET;
	socketInfo.sin_addr.s_addr = htonl(INADDR_ANY); // Use any address available to the system
	socketInfo.sin_port = htons(8080);      // Set port number
	return bind(socket.GetFileDescriptor(), (struct sockaddr *) &socketInfo, sizeof(socketInfo));
}

int ServerService::Listen(const Socket& socket)
{
	return listen(socket.GetFileDescriptor(), 1);
}

Socket ServerService::Accept(const Socket& socket)
{
	return Socket(accept(socket.GetFileDescriptor(), NULL, NULL));
}

int ServerService::Receive(const Socket& socket)
{
	int rc = 0;  // Actual number of bytes read
	char buf[512];
	// rc is the number of characters returned.
	// Note this is not typical. Typically one would only specify the number
	// of bytes to read a fixed header which would include the number of bytes
	// to read. See "Tips and Best Practices" below.
	rc = recv(socket.GetFileDescriptor(), buf, 512, 0);
	buf[rc]= (char) NULL;        // Null terminate string
	std::cout << "Number of bytes read: " << rc << std::endl;
	std::cout << "Received: " << buf << std::endl;
	return rc;
}
