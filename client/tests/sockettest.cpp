#include "gmock/gmock.h"

#include "socket.h"

#include "exceptionex.h"

using namespace ::testing;

TEST(SocketTest, CreateASocketWithConstructor)
{
   Socket socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
   ASSERT_THAT(socket.GetFileDescriptor(), Ne(-1));
}

TEST(SocketTest, CloseAutomaticalyASocketWhenTheObjectIsDestructed)
{
   Socket* socket1 = new Socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	delete socket1;
   Socket* socket2 = new Socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	delete socket2;
   ASSERT_THAT(Socket::GetObjectCounter(), Eq(0));
}

TEST(SocketTest, ThrowAnExceptionIfTheCreationOfTheSocketFails)
{
	ASSERT_THROW(Socket(0, 0, 0), socket_failure);
}
