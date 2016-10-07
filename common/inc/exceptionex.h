#pragma once

#include <stdexcept>

class socket_failure : public std::logic_error
{
public:
   socket_failure(const std::string& mess) : std::logic_error(mess + ": socket error ") {}
};

class connection_failure : public std::logic_error
{
public:
   connection_failure(const std::string& mess) : std::logic_error(mess + ": connection error ") {}
};

class send_failure : public std::logic_error
{
public:
   send_failure(const std::string& mess) : std::logic_error(mess + ": send error ") {}
};

class bind_failure : public std::logic_error
{
public:
   bind_failure(const std::string& mess) : std::logic_error(mess + ": bind error ") {}
};

class listen_failure : public std::logic_error
{
public:
   listen_failure(const std::string& mess) : std::logic_error(mess + ": listen error ") {}
};

class accept_failure : public std::logic_error
{
public:
   accept_failure(const std::string& mess) : std::logic_error(mess + ": accept error ") {}
};

class receive_failure : public std::logic_error
{
public:
   receive_failure(const std::string& mess) : std::logic_error(mess + ": receive error ") {}
};

class stop_server : public std::logic_error
{
public:
   stop_server() : std::logic_error("server stopped") {}
};
