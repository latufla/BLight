#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class EngineConnector
{
public:
	EngineConnector(void);
	~EngineConnector(void);

 	void start(void(*)(int));
 
 	static void printDebug(string);
 
	static const int FPS;

protected:
	void init();
	
private:
	bool shouldStop(RenderWindow&);
	Int32 shouldDoStep(Clock&);
};

