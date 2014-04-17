#pragma once
#include "stdafx.h"
#include "Command.h"
#include "QuestGoal.h"
#include "QuestInfo.h"
#include <vector>

class QuestBase
{
public:
	QuestBase();
	QuestBase(const QuestInfo&);
	~QuestBase(void);

	bool notify(CommandType, string, unsigned int);
	bool completed();

	unsigned int getId() const { return id; }
	void setId(unsigned int val) { id = val; }

	std::string getName() const { return name; }
	void setName(std::string val) { name = val; }

protected:
	unsigned int id;
	string name;

	vector<QuestGoal*> goals;
};

