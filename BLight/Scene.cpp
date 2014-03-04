#include "Scene.h"

void Scene::draw()
{
	for(auto it = drawList.cbegin(); it != drawList.cend(); it++){
		(*it)->draw();
	}
}

void Scene::addChild(ViewBase* v)
{
	drawList.push_back(v);
}

void Scene::addChild(TextBase* t)
{
	drawList.push_back(t);
}

