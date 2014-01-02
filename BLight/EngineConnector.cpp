#include "EngineConnector.h"

const int EngineConnector::FPS = 60;

void EngineConnector::start( void(*mainLoop)(int) )
{
	RenderWindow window(sf::VideoMode(1024, 768), "");
	window.setFramerateLimit(FPS);

	Clock timer;
	while (window.isOpen()){

		if(shouldStop(window))
			window.close();
		
		window.clear(Color::White);
		
		Int32 step = shouldDoStep(timer);
		//if(step)
		mainLoop(step);
			
		window.display();
	}
}

void EngineConnector::printDebug( string str)
{
	cout << str << endl;
}

bool EngineConnector::shouldStop( RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event)){
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
	return timer.getElapsedTime().asMilliseconds();
}
