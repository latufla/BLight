#include "Infos.h"
#include "JsonConnector.h"

map<string, ObjectInfo*> Infos::nameToInfo;

void Infos::init(FILE* f)
{
	vector<ObjectInfo*>* res = JsonConnector::getInstance().createInfosFromJson(f);
	for(auto it = res->cbegin(); it != res->cend(); ++it){
		nameToInfo[((*it))->name] = (*it);
	}

	delete res; // but not infos
}

ObjectInfo* Infos::getInfoBy(string name)
{
	return nameToInfo[name];
}