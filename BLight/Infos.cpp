#include "Infos.h"
#include "YamlConnector.h"
#include <iosfwd>

map<string, ObjectInfo*> Infos::nameToInfo;
vector<QuestInfo*> Infos::questInfos;

void Infos::init(string path)
{
	vector<ObjectInfo*>* res= YamlConnector::getInstance().createInfos(path + "game_objects.yaml");	
	for(auto it = res->cbegin(); it != res->cend(); ++it){
		nameToInfo[((*it))->name] = (*it);
	}
	delete res;

	vector<QuestInfo*>* quests = YamlConnector::getInstance().createQuestInfos(path + "quests.yaml");	
	for(auto it = quests->cbegin(); it != quests->cend(); ++it){
		questInfos.push_back(*it);
	}
	delete quests; 
}

ObjectInfo* Infos::getInfoBy(string name)
{
	return nameToInfo[name];
}

