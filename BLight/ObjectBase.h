#pragma once
#include "stdafx.h"
#include "EventDispatcher.h"
#include <utility>
#include <map>
#include "CustomPoint.h"
#include "CustomPolygon.h"

using namespace std;

class ObjectBase : public EventDispatcher
{
public:
	ObjectBase(void);
	ObjectBase(int, string);

	~ObjectBase(void);

	operator string();
	bool operator == (ObjectBase);
	
	int getId();
	void setId(int);

	string getName();
	void setName(string);

	bool fireUpdates();

	// Ph
	// initial
	void setPolygonShape(CustomPolygon*);

	void setDensity(float);
	void setFriction(float);
	void setRestitution(float);
	// end initial

	CustomPoint getPosition();
	float getRotation();

	vector<CustomPoint>* getVertexes();
	// end Ph
	
protected:
	void init(int, string);

	string name;
	vector<CustomPoint>* vertexes;
};

