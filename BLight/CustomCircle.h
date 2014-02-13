#pragma once
#include "stdafx.h"
#include "CustomPoint.h"
class CustomCircle
{
public:
	CustomCircle(void);
	CustomCircle(CustomPoint, float);
	~CustomCircle(void);

	void setPosition(CustomPoint);
	CustomPoint getPosition();
	
	void setRadius(float);
	float getRadius();

	CustomPoint getOrigin();

	virtual string getType(){return TYPE();};
	static string TYPE(){return "Circle";};

protected:
	CustomPoint position;
	float radius;
};

