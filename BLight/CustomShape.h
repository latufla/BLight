#pragma once
#include "stdafx.h"

enum ShapeType{NONE, POLYGON, CIRCLE};

class CustomShape
{
public:
	CustomShape(void);
	~CustomShape(void);
		
	virtual CustomShape* clone(){return nullptr;}

	virtual ShapeType getType(){return NONE;};

	static bool isPolygon(CustomShape* shape){return shape->getType() == POLYGON;};
	static bool isCircle(CustomShape* shape){return shape->getType() == CIRCLE;};
};

