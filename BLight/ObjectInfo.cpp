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

	for (auto it = drop.cbegin(); it != drop.cend(); ++it){
		delete (*it).second;
	}
	drop.clear();
}

bool ObjectInfo::canApplyCommand(CommandType command, string commander)
{
	for (auto it = applicableCommands.cbegin(); it != applicableCommands.cend(); ++it){
		if((*it).first == command){
			for (auto st = (*it).second.cbegin(); st != (*it).second.cend(); ++st){
				if((*st) == commander)
					return true;
			}
		}			
	}
	return false;
}
