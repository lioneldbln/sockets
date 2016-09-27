#include "gmock/gmock.h"

#include "client.h"

#include "exceptionex.h"

using namespace ::testing;

class ServiceForClientStub : public Service
{
public:
	int Connect(const Socket& socket) override {
		return -1;
	}

   int Send(const Socket& socket, const std::string& mess) override {
		return -1;
	}
};

TEST(ClientTest, ThrowAnExceptionIfTheConnectionFails)
{
   Client client(std::move(Socket{}), std::unique_ptr<ServiceForClientStub>{new ServiceForClientStub()});
   ASSERT_THROW(client.Connect(), connection_failure);
}

TEST(ClientTest, ThrowAnExceptionIfTheSendOperationFails)
{
   Client client(std::move(Socket{}), std::move(std::unique_ptr<ServiceForClientStub>{new ServiceForClientStub()}));
   ASSERT_THROW(client.Send("Hello World!"), send_failure);
}
