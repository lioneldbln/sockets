#include "gmock/gmock.h"

#include "socket.h"

using namespace ::testing;

TEST(SocketTest, CreateASocket)
{
   Socket socket;
   int socket_family = AF_INET;
   int socket_type = SOCK_STREAM;
   int protocol = IPPROTO_IP;
   ASSERT_THAT(socket.Create(socket_family, socket_type, protocol),Ne(-1));
}
