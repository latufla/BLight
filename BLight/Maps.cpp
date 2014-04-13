#include "Maps.h"
#include "Config.h"
#include "YamlConnector.h"

vector<ControllerBase*>* Maps::createMap()
{
	Infos::init("config/game_objects.yaml");	

	MapInfo* mapInfo = YamlConnector::getInstance().createMap("config/level_1.yaml");			
	
	vector<ControllerBase*>* res = new vector<ControllerBase*>();
	auto items = &mapInfo->infoNameToData;
	for(auto it = items->cbegin(); it != items->cend(); ++it){
		ObjectInfo* info = Infos::getInfoBy(it->first);
		ControllerBase* c = Config::field->createObjectController(it->second.first, *info, it->second.second);
		res->push_back(c);
	}	
	delete mapInfo;
	
	return res;
}

