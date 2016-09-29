#include "gmock/gmock.h"

#include "exceptionex.h"
#include "server.h"
#include "iserverservice.h"

class ServerServiceStub : public IServerService
{
public:
	int Bind(const Socket& socket) override {
		return -1;
	}

	int Listen(const Socket& socket) override {
		return -1;
   }

   Socket Accept(const Socket& socket) override {
		return Socket();
	}

   int Receive(const Socket& socket) override {
		return -1;
	}
};

TEST(ServerTest, ThrowAnExceptionIfBindFails)
{
	Server server(std::move(Socket{}), std::move(std::unique_ptr<IServerService>{new ServerServiceStub()}));
   ASSERT_THROW(server.Bind(), bind_failure);
}

TEST(ServerTest, ThrowAnExceptionIfListenFails)
{
	Server server(std::move(Socket{}), std::move(std::unique_ptr<IServerService>{new ServerServiceStub()}));
   ASSERT_THROW(server.Listen(), listen_failure);
}

TEST(ServerTest, ThrowAnExceptionIfAcceptFails)
{
	Server server(std::move(Socket{}), std::move(std::unique_ptr<IServerService>{new ServerServiceStub()}));
   ASSERT_THROW(server.Accept(), accept_failure);
}

TEST(ServerTest, ThrowAnExceptionIfReceiveFails)
{
	Server server(std::move(Socket{}), std::move(std::unique_ptr<IServerService>{new ServerServiceStub()}));
   ASSERT_THROW(server.Receive(Socket{}), receive_failure);
}
