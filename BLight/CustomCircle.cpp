#include "CustomCircle.h"


CustomCircle::CustomCircle(void)
{
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
