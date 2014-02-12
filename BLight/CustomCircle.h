#pragma once
#include "stdafx.h"
#include "CustomPoint.h"
class CustomCircle
{
public:
	CustomCircle(void);
	~CustomCircle(void);

	void setPosition(CustomPoint);
	CustomPoint getPosition();
	
	void setRadius(int);
	int getRadius();

protected:
	CustomPoint position;
	int radius;
};

