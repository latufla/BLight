#pragma once
#include "stdafx.h"
#include "QuestBase.h"
#include "Command.h"
#include "IManager.h"
#include "Infos.h"

class QuestManager : public IManager
{
public:
	static QuestManager& getInstance(){
		static QuestManager instance;
		return instance;
	}

	void init(Infos&);
	bool doStep(int);
	
	bool add(QuestBase*);
	bool notify(CommandType, string);

private:
	QuestManager(){};
	QuestManager(QuestManager const&);              
	void operator=(QuestManager const&);

	~QuestManager();

	vector<QuestBase*> quests;
	vector<QuestBase*> completedQuests;

	map<string, map<CommandType, unsigned int>> targetToCommand;
};

