#pragma once
#include "stdafx.h"
#include "EventDispatcher.h"
#include <utility>
#include <map>
#include "CustomPoint.h"
#include "CustomPolygon.h"
#include "CustomShape.h"

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
	void setShape(CustomShape*);
	void setDensity(float);
	void setFriction(float);
	void setRestitution(float);

	CustomPoint getPosition();
	float getRotation();

	CustomShape* getShape();
	
	void applyLinearImpulse(CustomPoint*);
	void setLinearDamping(float);
	CustomPoint getGlobalCenter();
	// end Ph
	
protected:
	void init(int, string);

	string name;

	CustomShape* shape;
};

