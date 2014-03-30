#include "SceneController.h"


void SceneController::init()
{
}

void SceneController::draw()
{
	for(auto it = drawList.cbegin(); it != drawList.cend(); it++){
		(*it)->draw();
	}
}

void SceneController::addChild(IDrawable* v)
{
	if(v != nullptr)
		drawList.push_back(v);
}

void SceneController::removeChild( IDrawable* view)
{	
	if(view == nullptr)
		return;

	drawList.erase(remove_if(drawList.begin(), drawList.end(), [view](IDrawable* v) -> bool{
				return view == v;
	}), drawList.end());
}

