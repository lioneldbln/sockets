#pragma once

#include <unistd.h>
#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API
#include <utility>

class Socket
{
public:
   Socket() : Socket(-1) {};
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


private:
   int fd; // file descriptor
};
