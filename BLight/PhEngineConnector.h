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
	
	void createBody(ObjectBase*, int oType, const CustomPoint& pos);
	void destroyBody(ObjectBase*);
	void setShape(ObjectBase*, CustomPolygon*);
	void setShape(ObjectBase*, CustomCircle*);

	void setDensity(ObjectBase*, float);
	void setFriction(ObjectBase*, float);
	void setResitution(ObjectBase*, float);

	CustomPoint& getPosition(ObjectBase*, CustomPoint&);
	float getRotation(ObjectBase*);

	CustomShape* getShape(ObjectBase*, CustomPolygon*);
	CustomShape* getShape(ObjectBase*, CustomCircle*);

	void applyForce(ObjectBase*, const CustomPoint&);
	void applyLinearImpulse(ObjectBase*, const CustomPoint&);
	void setLinearDamping(ObjectBase*, float);
	void setLinearVelocity(ObjectBase*, const CustomPoint&);

	void setSensor(ObjectBase*, bool);

	CustomPoint& getGlobalCenter(ObjectBase*, CustomPoint&);

	void doStep(int);

	void addContactReceiver(BehaviorBase*);
	void removeContactReceiver(BehaviorBase*);

	bool contains(ObjectBase*, const CustomPoint&);

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

