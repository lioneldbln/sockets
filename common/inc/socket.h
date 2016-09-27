#pragma once

#include <unistd.h>
#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API

class Socket
{
public:
   Socket() : fd(-1) {};
   Socket(int socket_family, int socket_type, int protocol);
   ~Socket();

   int GetFileDescriptor() const {
      return fd;
   }

   static int GetObjectCounter() {
      return cnt;
   }   

private:
   void CloseSocket();

   int fd; // file descriptor 
   static int cnt;  
};
