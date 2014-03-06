#include "CustomCircle.h"


CustomCircle::CustomCircle(void)
{
}

CustomCircle::CustomCircle( CustomPoint position, float radius)
{
	this->position = position;
	this->radius = radius;
}


CustomCircle::~CustomCircle(void)
{
}

void CustomCircle::setRadius(float val)
{
	radius = val;
}

float CustomCircle::getRadius()
{
	return radius;
}

CustomPoint* CustomCircle::getOrigin()
{
	static CustomPoint origin;
	origin.x = origin.y = radius;
	return &origin;
}
