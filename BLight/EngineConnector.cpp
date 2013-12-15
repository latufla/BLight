#include "EngineConnector.h"
#include <ClanLib\core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h> 

using namespace std;
using namespace clan;

EngineConnector::EngineConnector(void)
{
	init(nullptr); // TODO: bad decision
}

EngineConnector::EngineConnector(MainFunction* main)
{
	init(main);
}


EngineConnector::~EngineConnector(void)
{
	
}

void EngineConnector::init(MainFunction* main)
{
	Application app(main);
}

void EngineConnector::start( void(*mainLoop)(int) )
{
	SetupCore setup_core;
	SetupDisplay setup_display; 
	SetupGL setup_gl;

	ConsoleWindow console_window("Console");
	
	DisplayWindow window("", 1024, 768); 

	Canvas canvas(window); 
	InputDevice keyboard = window.get_ic().get_keyboard(); 	

	int elapsedTime = 0;
	GameTime gameTime(60, 60);
	while (!keyboard.get_keycode(keycode_escape)) { 
		canvas.clear(Colorf::white);

		gameTime.update();
		mainLoop(gameTime.get_time_elapsed_ms());

		canvas.flush();
		window.flip();
		KeepAlive::process();
	}
}

void EngineConnector::printDebug( string str)
{
	Console::write_line(str);
}


