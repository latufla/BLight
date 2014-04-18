#pragma once
#include "stdafx.h"
#include "ObjectInfo.h"
#include "QuestInfo.h"
#include <vector>

class Infos
{
public:
	static void init(string);

	static ObjectInfo* getInfoBy(string);

	static vector<QuestInfo*>& getQuestInfos() { return questInfos; }

private:
	static map<string, ObjectInfo*> nameToInfo;
	static vector<QuestInfo*> questInfos;
	
};

