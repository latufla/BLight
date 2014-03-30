#include "Command.h"
#include "Infos.h"
#include "PopupManager.h"


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
	string iName = caller->getController()->getName();
	ObjectInfo* info = Infos::getInfoBy(iName);
	return info->canExecuteCommand(getType()); 
}

void Command::execute()
{
	ObjectBase* cObj = caller->getController()->getObject();
	ObjectInfo* info = Infos::getInfoBy(cObj->getName());
	DropInfo* drop = info->drop[getType()];
	if(canShowPopUp())
		showPopUp(drop, cObj->getGlobalCenter());
}

bool Command::canShowPopUp()
{
	return false;
}

void Command::showPopUp(DropInfo* drop, const CustomPoint& pos)
{
	PopupText* p = new PopupText();
	p->setText((drop->energy < 0 ? "-" : "+") + to_string(long long(drop->energy)));
	p->getPosition().set(pos);
	PopupManager::getInstance().add(p);
}
