#pragma once
#include <Box2D/Box2D.h>

using namespace std;

class PhEngineConnector
{
public:

	void init();
	void doStep(int);

protected:
	b2World* world;

	b2Body* groundBody;
	b2Body* body;
};

