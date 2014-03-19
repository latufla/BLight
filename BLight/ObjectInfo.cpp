#include "ObjectInfo.h"


ObjectInfo::ObjectInfo(void)
{
}


ObjectInfo::~ObjectInfo(void)
{
	delete shape;

	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		delete (*it);
	}
	behaviors.clear();
}