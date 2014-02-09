#include "CustomPoint.h"


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
	char strX[6];
	sprintf(strX, "%4.2f", x); 
	
	char strY[6];
	sprintf(strY, "%4.2f", y); 
	
	return string(" x: " + string(strX) + ", y: " + string(strY));
}
