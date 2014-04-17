#pragma once
#include "stdafx.h"

class QuestGoalInfo
{
public:
	QuestGoalInfo(void);
	~QuestGoalInfo(void);

	string command;
	string target;
	unsigned int count;
};

