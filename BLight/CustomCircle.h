#pragma once
#include "stdafx.h"
#include "CustomPoint.h"
#include "CustomShape.h"

class CustomCircle : public CustomShape
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

	ShapeType getType(){return CIRCLE;};

protected:
	CustomPoint position;
	float radius;
};

