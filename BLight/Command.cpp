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
	DropInfo* drop = info->drop[getType()]->first;
	if(drop != nullptr)
		cObj->setEnergy(cObj->getEnergy() + drop->energy);

	drop = info->drop[getType()]->second;
	if(drop != nullptr)
		target->setEnergy(target->getEnergy() + drop->energy);
}

bool Command::canShowPopup()
{
	return false;
}

void Command::showPopup(DropInfo* drop, const CustomPoint& pos)
{
	if(drop == nullptr || !canShowPopup())
		return;

	PopupText* p = new PopupText();
	p->setText((drop->energy > 0 ? "+" : "") + to_string(long long(drop->energy)));
	p->getPosition().set(pos);
	PopupManager::getInstance().add(p);
}
