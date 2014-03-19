#pragma once
#include "stdafx.h"
#include "CustomPoint.h"
#include "CustomShape.h"

class CustomCircle : public CustomShape
{
public:
	CustomCircle(void);
	CustomCircle(const CustomPoint&, float);
	~CustomCircle(void);

	CustomShape* clone(); 

	CustomPoint& getPosition(){return position;}
	
	void setRadius(float val){radius = val; }
	float getRadius(){return radius;}

	CustomPoint& getOrigin();

	ShapeType getType(){return CIRCLE;};

protected:
	CustomPoint position;
	CustomPoint origin;

	float radius;
};

