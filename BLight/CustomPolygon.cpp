#include "CustomPolygon.h"


CustomPolygon::CustomPolygon(void)
{
}

CustomPolygon::CustomPolygon( vector<CustomPoint> vertexes)
{
	this->vertexes = vertexes;
}

CustomPolygon::CustomPolygon( float width, float height)
{
	vertexes.push_back(CustomPoint(0, 0));
	vertexes.push_back(CustomPoint(width, 0));
	vertexes.push_back(CustomPoint(width, height));
	vertexes.push_back(CustomPoint(0, height));
}

CustomPolygon::~CustomPolygon(void)
{
}


void CustomPolygon::setVertexes( vector<CustomPoint> val)
{
	vertexes = val;
}

vector<CustomPoint>* CustomPolygon::getVertexes()
{
	return &vertexes;
}
