#pragma once
#include "Command.h"

template<typename T> Command* createInstance() { return new T; }

class CommandsFactory
{
public:
	static Command* create(string);
	static CommandType getType(string);

private:
	static void init();

	static map <string,  Command*(*)()> nameToInstance;
	static map <string,  CommandType> nameToType;

	static bool inited;
};