#include "ObjectInfo.h"

ObjectInfo::ObjectInfo(void)
{
	density = 0.0f;
	friction = 0.0f;
	restitution = 0.0f;
	linearDamping = 0.0f;
}


ObjectInfo::~ObjectInfo(void)
{
	delete shape;

	for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it){
		delete (*it);
	}
	behaviors.clear();
}

bool ObjectInfo::canExecuteCommand(CommandType command)
{
	for (auto it = drop.cbegin(); it != drop.cend(); ++it){
		if((*it).first == command)
			return true;
	}
	return false;
}
