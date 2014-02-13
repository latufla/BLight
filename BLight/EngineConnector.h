#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "CustomPoint.h"
#include "ObjectBase.h"
#include "CustomCircle.h"
#include "CustomPolygon.h"

using namespace sf;

class EngineConnector
{
public:
	
	static const int FPS;

	static const int MUL_X;
	static const int MUL_Y;
	static const int SCALE_X;
	static const int SCALE_Y;

	static const int WINDOW_W; 
	static const int WINDOW_H; 

	static void start(void(*)(int));
  	static void printDebug(string);
	
	static void drawShape(CustomPolygon*);
	static void drawShape(CustomCircle*);

	static void drawLine(CustomPoint, CustomPoint);

private:
	static bool shouldStop(RenderWindow*);
	static Int32 shouldDoStep(Clock&);
	
	static void applyAxises(CustomPoint*);
	
	static RenderWindow* window;

};

