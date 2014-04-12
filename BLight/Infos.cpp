#include "Infos.h"
#include "YamlConnector.h"
#include <iosfwd>

map<string, ObjectInfo*> Infos::nameToInfo;

void Infos::init(FILE* f)
{
	vector<ObjectInfo*>* res= YamlConnector::getInstance().createInfosFromYaml("config/game_objects.yaml");
	
	for(auto it = res->cbegin(); it != res->cend(); ++it){
		nameToInfo[((*it))->name] = (*it);
	}

	delete res; // but not infos
}

ObjectInfo* Infos::getInfoBy(string name)
{
	return nameToInfo[name];
}