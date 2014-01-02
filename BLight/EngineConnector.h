#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class EngineConnector
{
public:
	
	static const int FPS;

	static void start(void(*)(int));
  	static void printDebug(string);
 	
private:
	static bool shouldStop(RenderWindow&);
	static Int32 shouldDoStep(Clock&);
};

