#include "Infos.h"
#include "YamlConnector.h"
#include <iosfwd>


Infos::~Infos()
{
	for (auto it = nameToObjectInfo.cbegin(); it != nameToObjectInfo.cend(); it++){
		delete (it->second);
	}
	nameToObjectInfo.clear();

	for (auto it = questInfos.cbegin(); it != questInfos.cend(); it++){
		delete (*it);
	}
	questInfos.clear();

	for (auto it = mapInfos.cbegin(); it != mapInfos.cend(); it++){
		delete (*it);
	}
	mapInfos.clear();
}

void Infos::init(string path)
{
	vector<ObjectInfo*>* res= YamlConnector::getInstance().createInfos(path + "game_objects.yaml");	
	for(auto it = res->cbegin(); it != res->cend(); ++it){
		nameToObjectInfo[((*it))->name] = (*it);
	}
	delete res;

	vector<QuestInfo*>* quests = YamlConnector::getInstance().createQuestInfos(path + "quests.yaml");	
	for(auto it = quests->cbegin(); it != quests->cend(); ++it){
		questInfos.push_back(*it);
	}
	delete quests; 

	MapInfo* mapInfo = YamlConnector::getInstance().createMap(path + "level_1.yaml");			
	mapInfos.push_back(mapInfo);
}

ObjectInfo* Infos::getObjectInfoBy(string name)
{
	return nameToObjectInfo[name];
}
