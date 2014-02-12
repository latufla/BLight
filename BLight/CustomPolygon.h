#pragma once
#include "stdafx.h"
#include "CustomPoint.h"

class CustomPolygon
{
public:
	CustomPolygon(void);
	CustomPolygon(vector<CustomPoint>);
	CustomPolygon(float, float);

	~CustomPolygon(void);

	void setVertexes(vector<CustomPoint>);
	vector<CustomPoint>* getVertexes();

	virtual string getType(){return "Polygon";}

protected:
	vector<CustomPoint> vertexes;
};

