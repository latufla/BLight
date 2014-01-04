#include "PhEngineConnector.h"

void PhEngineConnector::init(Field* f)
{
	b2Vec2 gravity(0.0f, -10.0f);
	world = new b2World(gravity);
}

void PhEngineConnector::doStep(int stepInMSecs)
{
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	float32 step = stepInMSecs / 1000.0f;
	
	world->Step(step, velocityIterations, positionIterations);

	b2Body* b = world->GetBodyList();
	b2Vec2 position = b->GetPosition();
	float32 angle = b->GetAngle();
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}

void PhEngineConnector::createBody(ObjectBase* obj, int oType, pair<float, float> pos)
{
	b2BodyDef bodyDef;
	bodyDef.type = (b2BodyType)oType; 
	bodyDef.position.Set((float32)pos.first, (float32)pos.second);
	objectConnectors[obj] = world->CreateBody(&bodyDef);
}

void PhEngineConnector::setBoxShape( ObjectBase* obj, float hWidth, float hHeight)
{
	b2Body* b = objectConnectors[obj];
	
	b2PolygonShape shape;
	shape.SetAsBox(hWidth, hHeight);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	
	b->CreateFixture(&fixtureDef);
}

void PhEngineConnector::setDensity( ObjectBase* obj, float d)
{
	b2Fixture* fixture = objectConnectors[obj]->GetFixtureList();
	fixture->SetDensity((float32)d); 
}

void PhEngineConnector::setFriction( ObjectBase* obj, float f)
{
	b2Fixture* fixture = objectConnectors[obj]->GetFixtureList();
	fixture->SetFriction((float32)f);
}

void PhEngineConnector::setResitution( ObjectBase* obj, float r)
{
	b2Fixture* fixture = objectConnectors[obj]->GetFixtureList();
	fixture->SetRestitution((float32)r);
}


