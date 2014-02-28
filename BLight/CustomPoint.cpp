#include "CustomPoint.h"
#include <math.h>

CustomPoint::CustomPoint(void)
{
}

CustomPoint::CustomPoint( float x, float y)
{
	this->x = x;
	this->y = y;
}

CustomPoint::operator string()
{
	int modX = fmod(x, floor(x)) * 100;
	int modY = fmod(y, floor(y)) * 100;
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
