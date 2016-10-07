#include "gmock/gmock.h"

#include "client.h"
#include "exceptionex.h"

class ClientTest : public testing::Test
{
public:
	Client client;

	ClientTest() : client(std::move(TCPConnector::t_SocketService(new SocketServiceStub))) {
	}
};

TEST_F(ClientTest, ThrowAnExceptionIfTheConnectionFails)
{
   ASSERT_THROW(client.Connect(-1,-1,-1,-1,"-1.-1.-1.-1"), connection_failure);
}
