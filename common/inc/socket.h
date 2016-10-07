#pragma once

#include <utility>

class Socket
{
public:
	Socket() : fd(-1) {};
	explicit Socket(int fd_) : fd(fd_) {};
   Socket(int socket_family, int socket_type, int protocol);
	~Socket();

	Socket(const Socket& x) = delete;
   Socket& operator=(const Socket& x) = delete;

	friend void swap(Socket& first, Socket& second) {
		using std::swap;
		swap(first.fd, second.fd);
	}

	Socket(Socket&& x) : Socket() {
		swap(*this, x);
	}
	Socket& operator=(Socket&& x) {
		swap(*this, x);
		return *this;
	}

   int GetFileDescriptor() const {
      return fd;
   }

protected:
	int fd;
};
