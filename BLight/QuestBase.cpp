#include "QuestBase.h"
#include "CommandsFactory.h"


QuestBase::QuestBase(void)
{
}

QuestBase::QuestBase(const QuestInfo& info)
{	
	id = info.id;
	name = info.name;
	for(auto it = info.goals.cbegin(); it != info.goals.cend(); ++it){
		goals.push_back(new QuestGoal(**it));
	}
}


QuestBase::~QuestBase(void)
{
	for (auto it = goals.cbegin(); it != goals.cend(); it++){
		delete (*it);
	}
	goals.clear();
}

bool QuestBase::notify(CommandType command, string target, unsigned int count)
{
	for(auto it = goals.begin(); it != goals.end(); ++it){
		if((*it)->completed())
			continue;

		if((*it)->command == command && (*it)->target == target)
			(*it)->currentCount += count;
	}
	return true;
}

bool QuestBase::completed()
{
	for(auto it = goals.cbegin(); it != goals.cend(); ++it){
		if(!(*it)->completed())
			return false;
	}
	return true;
}
