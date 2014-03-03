#include "Scene.h"

void Scene::draw()
{
	for(auto it = drawList.cbegin(); it != drawList.cend(); it++){
		(*it)->draw();
	}
}

void Scene::addChild(ControllerBase* c)
{
	drawList.push_back(c);
}

void Scene::addChild(TextBase* v)
{
	drawList.push_back(v);
}

