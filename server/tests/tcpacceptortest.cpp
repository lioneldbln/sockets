#include "gmock/gmock.h"

#include "tcpacceptor.h"
#include "exceptionex.h"

class TCPAcceptorTest : public testing::Test
{
public:
	TCPAcceptor tcpAcceptor;

	TCPAcceptorTest() : tcpAcceptor(std::move(TCPAcceptor::t_SocketService(std::move(new SocketServiceStub)))) {
	}
};

TEST_F(TCPAcceptorTest, ThrowAnExceptionIfStartingListeningFails)
{
	ASSERT_THROW(tcpAcceptor.Start(-1,-1,-1,-1), bind_failure);
}

TEST_F(TCPAcceptorTest, ThrowAnExceptionIfAcceptingTheConnectionFails)
{
	TCPStream tcpStream(0,"",Socket{});
	ASSERT_ANY_THROW(tcpAcceptor.Accept(tcpStream));
}
