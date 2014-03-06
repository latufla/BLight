#include "ViewBase.h"
#include "EngineConnector.h"

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
		EngineConnector::drawShape((CustomPolygon*)sp);
	else if(CustomShape::isCircle(sp))
		EngineConnector::drawShape((CustomCircle*)sp);
}
