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

void CustomCircle::setPosition( CustomPoint val)
{
	position = val;
}

CustomPoint CustomCircle::getPosition()
{
	return position;
}

void CustomCircle::setRadius(float val)
{
	radius = val;
}

float CustomCircle::getRadius()
{
	return radius;
}

CustomPoint CustomCircle::getOrigin()
{
	return CustomPoint(radius, radius);
}
