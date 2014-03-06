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

void SceneController::addChild(IDrawable* v)
{
	drawList.push_back(v);
}

// IDrawable* SceneController::removeChild(IDrawable* t)
// {
// // 	drawList.erase(remove_if(drawList.begin(), drawList.end(), [t](IDrawable* view) -> bool{
// // 		return t == view;
// // 	}), drawList.end());
// 	
// 	return t;
// }

