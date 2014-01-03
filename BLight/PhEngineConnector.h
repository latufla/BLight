#pragma once
#include <Box2D/Box2D.h>
#include "ObjectBase.h"
#include <map>

using namespace std;

class PhEngineConnector
{
public:
	static PhEngineConnector& getInstance()
	{
		static PhEngineConnector instance;
		return instance;
	}

	void init();
	void createBody(ObjectBase*, int oType, pair<float, float> pos);
	void setBoxShape(ObjectBase*, float, float);
	void setDensity(ObjectBase*, float);
	void setFriction(ObjectBase*, float);
	void setResitution(ObjectBase*, float);

	void doStep(int);

protected:
	b2World* world;

	b2Body* groundBody;
	b2Body* body;

private:
	PhEngineConnector() {};               
	PhEngineConnector(PhEngineConnector const&);              
	void operator=(PhEngineConnector const&);

	map<ObjectBase*, b2Body*> objects;
};

