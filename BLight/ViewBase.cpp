#include "ViewBase.h"

ViewBase::ViewBase(void) : object(nullptr)
{
}

ViewBase::~ViewBase(void)
{
}


void ViewBase::draw()
{	
	if(object == nullptr)
		return;

	CustomShape* sp = object->getShape();
	if(CustomShape::isPolygon(sp))
		EngineConnector::getInstance().drawShape((CustomPolygon*)sp);
	else if(CustomShape::isCircle(sp))
		EngineConnector::getInstance().drawShape((CustomCircle*)sp);
}
