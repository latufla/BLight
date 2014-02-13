#pragma once
#include <Box2D/Box2D.h>
#include "ObjectBase.h"
#include <map>
#include "Field.h"
#include "CustomPolygon.h"
#include "CustomCircle.h"

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
	//void setShape(ObjectBase*, CustomShape*);
	void setShape(ObjectBase*, CustomPolygon*);
	void setShape(ObjectBase*, CustomCircle*);


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

//	void setPolygon(ObjectBase*, CustomPolygon*);
//	void setCircle(ObjectBase*, CustomCircle*);

	b2World* world;
	map<ObjectBase*, b2Body*> objectConnectors;
};

