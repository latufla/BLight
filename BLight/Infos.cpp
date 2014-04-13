#include "Infos.h"
#include "YamlConnector.h"
#include <iosfwd>

map<string, ObjectInfo*> Infos::nameToInfo;

void Infos::init(string path)
{
	vector<ObjectInfo*>* res= YamlConnector::getInstance().createInfos(path);	
	for(auto it = res->cbegin(); it != res->cend(); ++it){
		nameToInfo[((*it))->name] = (*it);
	}
	delete res; // but not infos
}

ObjectInfo* Infos::getInfoBy(string name)
{
	return nameToInfo[name];
}