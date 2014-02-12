#include "PhEngineConnector.h"

void PhEngineConnector::init(Field* f)
{
	b2Vec2 gravity(0.0f, -10.0f);
	world = new b2World(gravity);
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

void PhEngineConnector::createBody(ObjectBase* obj, int oType, pair<float, float> pos)
{
	b2BodyDef bodyDef;
	bodyDef.type = (b2BodyType)oType; 
	bodyDef.position.Set((float32)pos.first, (float32)pos.second);
	objectConnectors[obj] = world->CreateBody(&bodyDef);
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

CustomPoint PhEngineConnector::getPosition(ObjectBase* obj)
{
	b2Body* body = objectConnectors[obj];
	b2Vec2 pos = body->GetPosition();
	CustomPoint res((float)pos.x, (float)pos.y);
	return res;
}

float PhEngineConnector::getRotation(ObjectBase* obj)
{
	b2Body* body = objectConnectors[obj];
	return (float)body->GetAngle();
}


void PhEngineConnector::setShape( ObjectBase* obj, CustomShape* poly )
{
	b2Body* b = objectConnectors[obj];

	b2PolygonShape shape;

	vector<CustomPoint>* vertexes = ((CustomPolygon*)poly)->getVertexes();
	CustomPoint* vertex;
	char n = vertexes->size();
	b2Vec2* vxsB2 = new b2Vec2[n];
	for(int i = 0; i < n; i++){
		vertex = &vertexes->at(i);
		vxsB2[i] = b2Vec2((float32)vertex->x, (float32)vertex->y);
	}
	shape.Set(vxsB2, n);
	delete [] vxsB2;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;

	b->CreateFixture(&fixtureDef);

}

CustomShape* PhEngineConnector::getShape( ObjectBase* obj, CustomShape* poly)
{
	CustomPoint pos = obj->getPosition();
	b2Fixture* fixture = objectConnectors[obj]->GetFixtureList();
	b2PolygonShape* shape = (b2PolygonShape*)(fixture->GetShape());	

	vector<CustomPoint>* vertexes = ((CustomPolygon*)poly)->getVertexes();
	b2Vec2 bVx; 
	char n = shape->GetVertexCount();
	for (char i = 0; i < n; i++){
		bVx = shape->GetVertex(i);
		(*vertexes)[i].x = (float)bVx.x + pos.x;
		(*vertexes)[i].y = (float)bVx.y + pos.y;
	}
	return poly;
}
