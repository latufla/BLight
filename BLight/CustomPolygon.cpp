#include "CustomPolygon.h"


CustomPolygon::CustomPolygon(void)
{
}

CustomPolygon::CustomPolygon(const vector<CustomPoint>& vertexes)
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

CustomShape* CustomPolygon::clone()
{
	return new CustomPolygon(vertexes);
}
