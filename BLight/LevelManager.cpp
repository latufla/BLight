#include "LevelManager.h"
#include "Config.h"
#include "YamlConnector.h"
#include "StatusViewManager.h"


LevelManager::~LevelManager()
{

}

void LevelManager::init(SceneController& scene, FieldController& field, Infos& infos)
{
	MapInfo* mapInfo = infos.getMapInfos()[0];
	vector<ControllerBase*>* res = new vector<ControllerBase*>();
	auto items = &mapInfo->infoNameToData;
	for(auto it = items->cbegin(); it != items->cend(); ++it){
		ObjectInfo* info = infos.getObjectInfoBy(it->first);
		ControllerBase* c = field.createObjectController(it->second.first, *info, it->second.second);
		scene.addChild(c->getView());
		applyAdditionalSettings(c);
	}	
}

void LevelManager::applyAdditionalSettings(ControllerBase* c)
{
	if(c->getName() == "player")
		Config::player = c;

	if(c->getDisplayStatus())
		StatusViewManager::getInstance().addStatusView(c);
}
