#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "serviceforclient.h"

#include "socket.h"

int ServiceForClient::Connect(const Socket& socket)
{
	struct sockaddr_in remoteSocketInfo;
	remoteSocketInfo.sin_family = AF_INET;
	remoteSocketInfo.sin_port = htons(8080);
	inet_aton("127.0.0.1", &remoteSocketInfo.sin_addr);
   memset(remoteSocketInfo.sin_zero, '\0', sizeof(remoteSocketInfo.sin_zero));
	return connect(socket.GetFileDescriptor(), (struct sockaddr *)&remoteSocketInfo, sizeof(sockaddr_in));
}

int ServiceForClient::Send(const Socket& socket, const std::string& mess)
{
   const char* c_ = mess.c_str();
   int size = strlen(c_)+1;
	return send(socket.GetFileDescriptor(), c_, size, 0);
}
