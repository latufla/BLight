#include "Command.h"


Command::Command(void)
{
}


Command::~Command(void)
{
}

bool Command::tryToExecute()
{
	if(canExecute()){
		execute();
		return true;
	}
	return false;	
}

bool Command::canExecute()
{
	return true;
}

void Command::execute()
{

}
