#pragma once
#include "Info.h"
#include "QuestGoalInfo.h"

class QuestInfo : public Info
{
public:
	QuestInfo(void);
	~QuestInfo(void);
	
	vector<QuestGoalInfo> goals;
};

