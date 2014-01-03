#include "PhEngineConnector.h"

void PhEngineConnector::init()
{
	b2Vec2 gravity(0.0f, -10.0f);

	world = new b2World(gravity);

	// ground box
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	groundBody = world->CreateBody(&groundBodyDef);

	b2PolygonShape groundBoxShape;
	groundBoxShape.SetAsBox(50.0f, 10.0f);

	groundBody->CreateFixture(&groundBoxShape, 0.0f);
	// end ground box

	// falling box
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);

	body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBoxShape;
	dynamicBoxShape.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBoxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
}

void PhEngineConnector::doStep(int stepInMSecs)
{
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	float32 step = stepInMSecs / 1000.0f;
	world->Step(step, velocityIterations, positionIterations);

	b2Vec2 position = body->GetPosition();
	float32 angle = body->GetAngle();

	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}
