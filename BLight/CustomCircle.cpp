#include "CustomCircle.h"


CustomCircle::CustomCircle(void)
{

}

CustomCircle::CustomCircle(const CustomPoint& position, float radius)
{
	this->position = position;
	this->radius = radius;
}


CustomCircle::~CustomCircle(void)
{
}


CustomPoint* CustomCircle::getOrigin()
{	
	origin.x = origin.y = radius;
	return &origin;
}
