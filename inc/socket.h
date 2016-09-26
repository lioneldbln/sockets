#pragma once

#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
#include <netinet/in.h>  // Internet domain address structures and functions
#include <sys/socket.h>  // Structures and functions used for socket API

class Socket
{
public:
   int Create(int socket_family, int socket_type, int protocol){
      return socket(socket_family, socket_type, protocol);
   }
};
