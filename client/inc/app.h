#pragma once

#include <string>

class Client;

class App
{
public:
	void Run() const;

private:
	std::string GetLineFromConsole() const;
};
