#include "gmock/gmock.h"

#include "tcpstream.h"
#include "exceptionex.h"

class TCPStreamTest: public testing::Test {
public:
	TCPStream tcpStream;

	TCPStreamTest() : tcpStream(0, "0.0.0.0", std::move(Socket{}), std::move(TCPStream::t_SocketService(new SocketServiceStub))) {}
};

TEST_F(TCPStreamTest, ThrowAnExceptionIfSendingAMessageFails)
{
	ASSERT_THROW(tcpStream.Send("Hello!"), send_failure);
}

TEST_F(TCPStreamTest, ThrowAnExceptionIfReceivingAMessageFails)
{
	ASSERT_THROW(tcpStream.Receive(), receive_failure);
}
