#include "Command.h"
#include "Infos.h"
#include "PopupManager.h"
#include "CustomUtils.h"
#include "Config.h"
#include "QuestManager.h"


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
	ObjectBase* commander = caller->getController()->getObject();
	return info->canApplyCommand(getType(), commander->getName()); 
}

void Command::execute()
{
	ObjectBase* cObj = caller->getController()->getObject();
	ObjectInfo* info = Infos::getInfoBy(cObj->getName());
	DropInfo* drop = info->drop[getType()];
	if(drop == nullptr)
		return;

	cObj->setEnergy(cObj->getEnergy() + drop->caller[DropInfo::ENERGY]);
	cObj->setXp(cObj->getXp() + drop->caller[DropInfo::XP]);		
		
	target->setEnergy(target->getEnergy() + drop->target[DropInfo::ENERGY]);
	target->setXp(target->getXp() + drop->target[DropInfo::XP]);

	ObjectBase* player = Config::player->getObject();
	player->setEnergy(player->getEnergy() + drop->player[DropInfo::ENERGY]);
	player->setXp(player->getXp() + drop->player[DropInfo::XP]);

	QuestManager::getInstance().notify(getType(), target->getName());
}

bool Command::canShowPopup()
{
	return false;
}

void Command::showPopup(const map<string, int>& drop, const CustomPoint& pos)
{
	if(!canShowPopup())
		return;

	PopupText* p = new PopupText();

	string txt = "";
	int energy = drop.at(DropInfo::ENERGY);
	if(energy != 0)
		txt += (energy > 0 ? "en: +" : "en: ") + CustomUtils::iToS(energy) + "\n";

	int xp = drop.at(DropInfo::XP);
	if(xp != 0)
		txt += (xp > 0 ? "xp: +" : "xp: ") + CustomUtils::iToS(xp) + "\n";
	
	p->setText(txt);
	p->getPosition().set(pos);
	
	PopupManager::getInstance().add(p);
}
