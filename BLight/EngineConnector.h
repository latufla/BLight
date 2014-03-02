#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/window/Mouse.hpp>

#include "CustomPoint.h"
#include "ObjectBase.h"
#include "CustomCircle.h"
#include "CustomPolygon.h"
#include "SFML/Graphics/Font.hpp"
#include "TextBase.h"

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

	static void drawPoint(CustomPoint);
	static void drawLine(CustomPoint, CustomPoint);

	static void drawText(TextBase*);

	static bool isLeftMouseButtonPressed();
	static CustomPoint getMousePosition();

private:
	static bool shouldStop(RenderWindow*);
	static Int32 shouldDoStep(Clock&);
	
	static void applyAxises(CustomPoint*);
	static void declineAxises(CustomPoint*);

	static RenderWindow* window;

	static map<string, sf::Font> fonts;
};

