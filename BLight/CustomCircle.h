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
	
	void setRadius(float);
	float getRadius();

	virtual string getType(){return "Circle";};

protected:
	CustomPoint position;
	float radius;
};

