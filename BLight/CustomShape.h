#pragma once
#include "stdafx.h"
#include "CustomCircle.h"
#include "CustomPolygon.h"

class CustomShape
{
public:
	CustomShape(void);
	~CustomShape(void);
		
	virtual string getType(){return "";};

	static bool isCircle(CustomShape* shape){return shape->getType() == CustomCircle::TYPE();};
	static bool isPolygon(CustomShape* shape){return shape->getType() == CustomPolygon::TYPE();};
};

