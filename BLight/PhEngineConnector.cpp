#include "PhEngineConnector.h"
#include "CustomCircle.h"

void PhEngineConnector::init(Field* f)
{
	b2Vec2 gravity(0.0f, 0.0f);
	world = new b2World(gravity);
	
	contactListener = new CustomContactListener();
	world->SetContactListener(contactListener);	
}

// TODO: if it`s network multi player
// make several 1 / 60 steps stepInMSecs / (1000 / 60) times
void PhEngineConnector::doStep(int stepInMSecs)
{
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	float32 step = 1.0f / 60.0f; // single player or split screen	
	world->Step(step, velocityIterations, positionIterations); 
}

void PhEngineConnector::createBody(ObjectBase* obj, int oType, const CustomPoint& pos)
{
	static b2BodyDef bodyDef;
	bodyDef.type = (b2BodyType)oType; 
	bodyDef.position.Set((float32)pos.x, (float32)pos.y);
	
	b2Body* body = world->CreateBody(&bodyDef);
	
	objectToBody[obj] = body;
	bodyToObject[body] = obj;
}

void PhEngineConnector::destroyBody(ObjectBase* obj)
{
	b2Body* body = objectToBody[obj];
	objectToBody.erase(obj);
	bodyToObject.erase(body);	
	world->DestroyBody(body);
}


void PhEngineConnector::setDensity( ObjectBase* obj, float d)
{
	b2Fixture* fixture = objectToBody[obj]->GetFixtureList();
	fixture->SetDensity((float32)d); 
}

void PhEngineConnector::setFriction( ObjectBase* obj, float f)
{
	b2Fixture* fixture = objectToBody[obj]->GetFixtureList();
	fixture->SetFriction((float32)f);
}

void PhEngineConnector::setResitution( ObjectBase* obj, float r)
{
	b2Fixture* fixture = objectToBody[obj]->GetFixtureList();
	fixture->SetRestitution((float32)r);
}

CustomPoint& PhEngineConnector::getPosition(ObjectBase* obj, CustomPoint& outPosition)
{
	b2Body* body = objectToBody[obj];
	const b2Vec2& pos = body->GetPosition();
	outPosition.set(pos.x, pos.y);
	return outPosition;
}

float PhEngineConnector::getRotation(ObjectBase* obj)
{
	b2Body* body = objectToBody[obj];
	return (float)body->GetAngle();
}

void PhEngineConnector::setShape(ObjectBase* obj, CustomPolygon* poly)
{
	b2Body* b = objectToBody[obj];
	static b2PolygonShape shape;

	vector<CustomPoint>& vertexes = poly->getVertexes();
	CustomPoint* vertex;
	char n = vertexes.size();
	b2Vec2* vxsB2 = new b2Vec2[n];
	for(int i = 0; i < n; i++){
		vertex = &vertexes[i];
		vxsB2[i] = b2Vec2((float32)vertex->x, (float32)vertex->y);
	}
	shape.Set(vxsB2, n);
	delete [] vxsB2;

	static b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;

	b->CreateFixture(&fixtureDef);
}

void PhEngineConnector::setShape( ObjectBase* obj, CustomCircle* circle)
{
	b2Body* b = objectToBody[obj];
	
	static b2CircleShape shape;
	shape.m_radius = circle->getRadius();
	CustomPoint& p = circle->getPosition();
	shape.m_p.Set(p.x, p.y); 

	static b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;

	b->CreateFixture(&fixtureDef);
}


CustomShape* PhEngineConnector::getShape( ObjectBase* obj, CustomPolygon* poly)
{
	CustomPoint& pos = obj->getPosition();
	b2Fixture* fixture = objectToBody[obj]->GetFixtureList();

	b2PolygonShape* shape = (b2PolygonShape*)(fixture->GetShape());	

	vector<CustomPoint>& vertexes = ((CustomPolygon*)poly)->getVertexes();
	char n = shape->GetVertexCount();
	for (char i = 0; i < n; i++){
		const b2Vec2& bVx = shape->GetVertex(i);
		vertexes[i].x = (float)bVx.x + pos.x;
		vertexes[i].y = (float)bVx.y + pos.y;
	}
	return (CustomShape*)poly;
};

CustomShape* PhEngineConnector::getShape( ObjectBase* obj, CustomCircle* circle )
{
	CustomPoint& pos = obj->getPosition();
	b2Fixture* fixture = objectToBody[obj]->GetFixtureList();
	
	b2CircleShape* shape = (b2CircleShape*)(fixture->GetShape());
	circle->setRadius(shape->m_radius);
	circle->getPosition().set(shape->m_p.x + pos.x, shape->m_p.y + pos.y);
	
	return (CustomShape*)circle;
}

void PhEngineConnector::applyLinearImpulse( ObjectBase* obj, const CustomPoint& impulse )
{
	b2Body* b = objectToBody[obj];
	static b2Vec2 bImpulse;
	bImpulse.Set(impulse.x, impulse.y);
	b->ApplyLinearImpulse(bImpulse, b->GetWorldCenter());
}

void PhEngineConnector::setLinearDamping( ObjectBase* obj, float damping )
{
	b2Body* b = objectToBody[obj];
	b->SetLinearDamping(damping);
}

CustomPoint& PhEngineConnector::getGlobalCenter(ObjectBase* obj, CustomPoint& outGlobalCenter)
{
	b2Body* b = objectToBody[obj];
	const b2Vec2& bCenter = b->GetWorldCenter();
	outGlobalCenter.set(bCenter.x, bCenter.y);
	return outGlobalCenter;
}

void PhEngineConnector::applyForce(ObjectBase* obj, const CustomPoint& force)
{
	b2Body* b = objectToBody[obj];
	
	static b2Vec2 bForce;
	bForce.Set(force.x, force.y);
	b->ApplyForceToCenter(bForce);	
}

void PhEngineConnector::setLinearVelocity( ObjectBase* obj, const CustomPoint& vel)
{
	b2Body* b = objectToBody[obj];

	static b2Vec2 bVel;
	bVel.x = vel.x;
	bVel.y = vel.y;
	b->SetLinearVelocity(bVel);	
}

void PhEngineConnector::addContactReceiver( BehaviorBase* b)
{
	contactReceivers.push_back(b);
}

void PhEngineConnector::removeContactReceiver( BehaviorBase* b)
{
	contactReceivers.erase(remove_if(contactReceivers.begin(), contactReceivers.end(), [b](BehaviorBase* bhr) -> bool{
		return b == bhr;
	}), contactReceivers.end());
}

void PhEngineConnector::setSensor( ObjectBase* obj, bool val )
{
	b2Body* b = objectToBody[obj];
	b->GetFixtureList()->SetSensor(val);
}



