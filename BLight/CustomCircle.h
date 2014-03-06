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

	CustomPoint* getPosition(){return &position;}
	
	void setRadius(float);
	float getRadius();

	CustomPoint* getOrigin();

	ShapeType getType(){return CIRCLE;};

protected:
	CustomPoint position;
	float radius;
};

