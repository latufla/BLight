#pragma once
#include "stdafx.h"
#include "CustomPoint.h"
#include "CustomShape.h"

class CustomPolygon : public CustomShape
{
public:
	CustomPolygon(void);
	CustomPolygon(const vector<CustomPoint>&);
	CustomPolygon(float, float);

	~CustomPolygon(void);

	CustomShape* clone();

	vector<CustomPoint>& getVertexes(){return vertexes;}

	ShapeType getType(){return POLYGON;};

protected:
	vector<CustomPoint> vertexes;
};

