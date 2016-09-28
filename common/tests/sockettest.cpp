#include "gmock/gmock.h"

#include "socket.h"

#include "exceptionex.h"

using namespace ::testing;


TEST(SocketTest, ThrowAnExceptionIfTheCreationOfTheSocketFails)
{
	ASSERT_THROW(Socket(0, 0, 0), socket_failure);
}
