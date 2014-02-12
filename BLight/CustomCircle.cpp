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

void CustomCircle::setRadius( int val)
{
	radius = val;
}

int CustomCircle::getRadius()
{
	return radius;
}
