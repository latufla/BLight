#pragma once
#include "stdafx.h"
#include "ObjectInfo.h"
#include "QuestInfo.h"
#include <vector>
#include "MapInfo.h"

class Infos
{
public:
	static Infos& getInstance(){
		static Infos instance;
		return instance;
	}

	void init(string);

	ObjectInfo* getObjectInfoBy(string);
	vector<QuestInfo*>& getQuestInfos() { return questInfos; }
	vector<MapInfo*>& getMapInfos(){return mapInfos; }

private:
	Infos(){};
	Infos(Infos const&);
	void operator=(Infos const&);
	
	~Infos();
	
	map<string, ObjectInfo*> nameToObjectInfo;
	vector<QuestInfo*> questInfos;
	vector<MapInfo*> mapInfos;	
};