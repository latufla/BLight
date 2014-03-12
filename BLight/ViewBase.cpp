#include "ViewBase.h"

ViewBase::ViewBase(void) : object(nullptr)
{
	cout << "\n" + string(__FUNCTION__);
}

ViewBase::~ViewBase(void)
{
	cout << "\n" + string(__FUNCTION__);
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
