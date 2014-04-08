#include "Maps.h"
#include "JsonConnector.h"
#include "Config.h"


vector<ControllerBase*>* Maps::createMap()
{
	FILE* infos = fopen ("config/game_objects.json" , "r");	
	Infos::init(infos);
	fclose(infos);

	FILE* level = fopen ("config/level_1.json" , "r");	
	MapInfo* mapInfo = JsonConnector::getInstance().createMapFromJson(level);		
	fclose(level);

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

