#include "SceneController.h"


void SceneController::init()
{
	energyText.setText("Energy: ");	
	energyText.getPosition()->set(1.0f, 38.0f);
	addChild(&energyText);
}

void SceneController::draw()
{
	for(auto it = drawList.cbegin(); it != drawList.cend(); it++){
		(*it)->draw();
	}
}

void SceneController::addChild(ViewBase* v)
{
	drawList.push_back(v);
}

void SceneController::addChild(TextBase* t)
{
	drawList.push_back(t);
}

