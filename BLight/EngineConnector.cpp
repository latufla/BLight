#include "EngineConnector.h"

const int EngineConnector::FPS = 30;

const int EngineConnector::MUL_X = 20;
const int EngineConnector::MUL_Y = 20;
const int EngineConnector::SCALE_X = 1;
const int EngineConnector::SCALE_Y = -1;

const int EngineConnector::WINDOW_W = 1024;
const int EngineConnector::WINDOW_H = 768;

RenderWindow* EngineConnector::window = nullptr;

void EngineConnector::start( void(*mainLoop)(int) )
{
	window = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H), "");
	window->setFramerateLimit(FPS);

	Clock timer;
	while (window->isOpen()){

		if(shouldStop(window))
			window->close();
		
		window->clear(Color::White);
		
		Int32 step = shouldDoStep(timer);
		if(step)
			mainLoop(step);
			
		window->display();
	}
}

void EngineConnector::printDebug( string str)
{
	cout << str << endl;
}

bool EngineConnector::shouldStop( RenderWindow* window)
{
	Event event;
	while (window->pollEvent(event)){
		if (event.type == Event::Closed)
			return true;
	}
	return false;
}

Int32 EngineConnector::shouldDoStep( Clock& timer)
{
// 	Int32 stepInterval = 1000 / FPS;
// 	Int32 time = timer.getElapsedTime().asMilliseconds();
// 	if(time > stepInterval){
// 		timer.restart();
// 		return time;
// 	}
// 	return 0;
	Int32 time = timer.getElapsedTime().asMilliseconds();
	timer.restart();
	return time;
}

void EngineConnector::drawLine( CustomPoint b, CustomPoint e)
{
	applyAxises(&b);
	applyAxises(&e);

	static Vertex line[] =	{
		Vertex(Vector2f(), Color::Magenta),
		Vertex(Vector2f(), Color::Magenta)
	};

	line[0].position.x = b.x; 
	line[0].position.y = b.y;

	line[1].position.x = e.x; 
	line[1].position.y = e.y; 

	window->draw(line, 2, Lines);
}

void EngineConnector::applyAxises( CustomPoint* outPoint)
{
	outPoint->x = outPoint->x * MUL_X * SCALE_X;
	outPoint->y = outPoint->y * MUL_Y * SCALE_Y + WINDOW_H;
}

void EngineConnector::drawObject( ObjectBase* obj)
{
	auto vxs = obj->getVertexes();
	for (auto it = vxs.cbegin(); it != vxs.cend() - 1; it++){
		EngineConnector::drawLine(*it, *(it + 1));
	}
}



