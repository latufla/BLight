#include "SceneController.h"
#include "EngineConnector.h"


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

void SceneController::addChild(IDrawable* v)
{
	drawList.push_back(v);
}

void SceneController::removeChild( IDrawable* view)
{	
	drawList.erase(remove_if(drawList.begin(), drawList.end(), [view](IDrawable* v) -> bool{
				return view == v;
	}), drawList.end());
}

