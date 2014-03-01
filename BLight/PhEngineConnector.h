#pragma once
#include <Box2D/Box2D.h>
#include "ObjectBase.h"
#include <map>
#include "Field.h"
#include "CustomPolygon.h"
#include "CustomCircle.h"
#include "CustomContactListener.h"
#include "BehaviorBase.h"

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
	
	void createBody(ObjectBase*, int oType, CustomPoint pos);
	void setShape(ObjectBase*, CustomPolygon*);
	void setShape(ObjectBase*, CustomCircle*);

	void setDensity(ObjectBase*, float);
	void setFriction(ObjectBase*, float);
	void setResitution(ObjectBase*, float);

	CustomPoint getPosition(ObjectBase*);
	float getRotation(ObjectBase*);

	CustomShape* getShape(ObjectBase*, CustomPolygon*);
	CustomShape* getShape(ObjectBase*, CustomCircle*);

	void applyForce(ObjectBase*, CustomPoint*);
	void applyLinearImpulse(ObjectBase*, CustomPoint*);
	void setLinearDamping(ObjectBase*, float);
	void setLinearVelocity(ObjectBase*, CustomPoint*);

	void setSensor(ObjectBase*, bool);

	CustomPoint getGlobalCenter(ObjectBase*);

	void doStep(int);

	void addContactReceiver(BehaviorBase*);

private:
	PhEngineConnector() {};               
	PhEngineConnector(PhEngineConnector const&);              
	void operator=(PhEngineConnector const&);

	b2World* world;
	map<ObjectBase*, b2Body*> objectToBody;
	map<b2Body*, ObjectBase*> bodyToObject;
	
	vector<BehaviorBase*> contactReceivers;
	CustomContactListener* contactListener;
	
	friend class CustomContactListener;
};

