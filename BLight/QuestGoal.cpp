#include "QuestGoal.h"
#include "CommandsFactory.h"


QuestGoal::QuestGoal(void)
{
}

QuestGoal::QuestGoal(const QuestGoalInfo& info)
{
	command = CommandsFactory::getType(info.command);
	target = info.target;
	count = info.count;

	currentCount = 0;
}


QuestGoal::~QuestGoal(void)
{

}

bool QuestGoal::completed()
{
	return currentCount >= count;
}
