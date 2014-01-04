#pragma once
#include <Box2D/Box2D.h>
#include "ObjectBase.h"
#include <map>
#include "Field.h"

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
	void setBoxShape(ObjectBase*, float, float);
	void setDensity(ObjectBase*, float);
	void setFriction(ObjectBase*, float);
	void setResitution(ObjectBase*, float);

	pair<float, float> getPosition(ObjectBase*);
	float getRotation(ObjectBase*);

	void doStep(int);

private:
	PhEngineConnector() {};               
	PhEngineConnector(PhEngineConnector const&);              
	void operator=(PhEngineConnector const&);

	b2World* world;
	map<ObjectBase*, b2Body*> objectConnectors;
};

