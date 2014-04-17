#pragma once
#include "QuestGoalInfo.h"
#include "Command.h"

class QuestGoal
{
public:
	QuestGoal(void);
	QuestGoal(const QuestGoalInfo&);
	~QuestGoal(void);

	bool completed();

	CommandType command;
	string target;
	unsigned int count;

	unsigned int currentCount;
};

