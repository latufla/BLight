#include "PhEngineConnector.h"

void PhEngineConnector::init(Field* f)
{
	b2Vec2 gravity(0.0f, -10.0f);
	world = new b2World(gravity);
}

// TODO: if it`s network multi player
// make several 1 / 60 steps 
// stepInMSecs / (1000 / 60) times
void PhEngineConnector::doStep(int stepInMSecs)
{
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	float32 step = 1.0f / 60.0f; // single player or split screen	
	world->Step(step, velocityIterations, positionIterations); 
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

pair<float, float> PhEngineConnector::getPosition(ObjectBase* obj)
{
	b2Body* body = objectConnectors[obj];
	b2Vec2 pos = body->GetPosition();
	pair<float, float> res((float)pos.x, (float)pos.y);
	return res;
}

float PhEngineConnector::getRotation(ObjectBase* obj)
{
	b2Body* body = objectConnectors[obj];
	return (float)body->GetAngle();
}
