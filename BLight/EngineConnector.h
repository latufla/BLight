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
	static EngineConnector& getInstance()
	{
		static EngineConnector instance;
		return instance;
	}

	static const int FPS;

	static const int MUL_X;
	static const int MUL_Y;
	static const int SCALE_X;
	static const int SCALE_Y;

	static const int WINDOW_W; 
	static const int WINDOW_H; 

	static const int F;
	static const int D;

	void init(void(*)(int));

	void printDebug(string);
	void printDebugInstances();
	void printDebugControllers();

	void drawShape(CustomPolygon*);
	void drawShape(CustomCircle*);

	void drawPoint(CustomPoint);
	void drawLine(CustomPoint, CustomPoint);

	void drawText(TextBase*);

	bool isLeftMouseButtonPressed();
	CustomPoint& getMousePosition();

	bool isKeyPressed(int);

private:
	EngineConnector() {};               
	EngineConnector(EngineConnector const&);              
	void operator=(EngineConnector const&);

	bool shouldStop(RenderWindow*);
	Int32 shouldDoStep(Clock&);
	
	void applyAxises(CustomPoint&);
	void declineAxises(CustomPoint&);

	RenderWindow* window;
	map<string, sf::Font> fonts;
};

