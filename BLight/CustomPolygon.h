#pragma once
#include "stdafx.h"
#include "CustomPoint.h"
#include "CustomShape.h"

class CustomPolygon : public CustomShape
{
public:
	CustomPolygon(void);
	CustomPolygon(vector<CustomPoint>);
	CustomPolygon(float, float);

	~CustomPolygon(void);

	void setVertexes(vector<CustomPoint>);
	vector<CustomPoint>* getVertexes();

	ShapeType getType(){return POLYGON;};

protected:
	vector<CustomPoint> vertexes;

};

