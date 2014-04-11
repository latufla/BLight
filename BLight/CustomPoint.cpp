#include "CustomPoint.h"
#include <math.h>

CustomPoint::CustomPoint(void)
{
	x = y = 0.0f;
}

CustomPoint::CustomPoint( float x, float y)
{
	this->x = x;
	this->y = y;
}

// TODO: fix 0.xx error 
CustomPoint::operator string()
{
	float modX = fmod(x, floor(x)) * 100;
	float modY = fmod(y, floor(y)) * 100;
	return " x: " + to_string(long long(x)) + "." + to_string(long long(modX))
		 + " y: " + to_string(long long(y)) + "." + to_string(long long(modY));
}

float CustomPoint::getLength()
{
	return sqrt(pow(x, 2) + pow(y, 2));	
}

void CustomPoint::normalize(float weight)
{
	float length = getLength() / weight;
	x /= length;
	y /= length;
}

void CustomPoint::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CustomPoint::set(const CustomPoint& pos)
{
	this->x = pos.x;
	this->y = pos.y;
}

void CustomPoint::moveBy( const CustomPoint& delta)
{
	this->x += delta.x;
	this->y += delta.y;
}
