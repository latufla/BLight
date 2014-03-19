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

	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		delete (*it);
	}
	behaviors.clear();
}