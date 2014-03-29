#include "Command.h"
#include "Infos.h"


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
	ObjectInfo* info = Infos::getInfoBy(target->getName());
	return info->canApplyCommand(getType()); 
}

void Command::execute()
{

}
