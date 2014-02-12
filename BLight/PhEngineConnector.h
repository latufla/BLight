#pragma once
#include <Box2D/Box2D.h>
#include "ObjectBase.h"
#include <map>
#include "Field.h"
#include "CustomPolygon.h"

using namespace std;

class PhEngineConnector
{
public:
	static PhEngineConnector& getInstance()
	{
		static PhEngineConnector instance;
		return instance;
	}

	void init(Field*);
	
	void createBody(ObjectBase*, int oType, pair<float, float> pos);
	void setShape(ObjectBase*, CustomShape* poly);

	void setDensity(ObjectBase*, float);
	void setFriction(ObjectBase*, float);
	void setResitution(ObjectBase*, float);

	CustomPoint getPosition(ObjectBase*);
	float getRotation(ObjectBase*);

	CustomShape* getShape(ObjectBase*, CustomShape*);

	void doStep(int);

private:
	PhEngineConnector() {};               
	PhEngineConnector(PhEngineConnector const&);              
	void operator=(PhEngineConnector const&);

	b2World* world;
	map<ObjectBase*, b2Body*> objectConnectors;
};

