#include "gmock/gmock.h"

#include "tcpconnector.h"
#include "exceptionex.h"

class TCPConnectorTest : public testing::Test
{
public:
	TCPConnector tcpConnector;

	TCPConnectorTest() : tcpConnector(std::move(TCPConnector::t_SocketService(new SocketServiceStub))) {
	}
};

TEST_F(TCPConnectorTest, ThrowAnExceptionIfTheConnectionFails)
{
   ASSERT_THROW(tcpConnector.Connect(-1,-1,-1,-1,"-1.-1.-1.-1"), connection_failure);
}
