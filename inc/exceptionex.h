#pragma once

#include <stdexcept>

class socket_failure : public std::logic_error
{
public:
   socket_failure(const std::string& mess) : std::logic_error(mess) {}
};

class connection_failure : public std::logic_error
{
public:
   connection_failure(const std::string& mess) : std::logic_error(mess) {}
};

class send_failure : public std::logic_error
{
public:
   send_failure(const std::string& mess) : std::logic_error(mess) {}
};
