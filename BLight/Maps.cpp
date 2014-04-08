#include "Maps.h"
#include "StatusViewManager.h"
#include "JsonConnector.h"


vector<ControllerBase*>* Maps::createMap(FieldController& field)
{
	FILE* infos = fopen ("config/game_objects.json" , "r");	
	Infos::init(infos);
	fclose(infos);

	FILE* level = fopen ("config/level_1.json" , "r");	
	vector<ControllerBase*>* res = JsonConnector::getInstance().createMapFromJson(level);	
	fclose(level);
	return res;
}
