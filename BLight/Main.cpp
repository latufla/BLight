#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h> 

#include "stdafx.h"
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "ControllerBase.h"
#include "StubBehavior.h"

using namespace clan; 

void initialTests();

void slot_function1(int p1, int p2)
{
	clan::Console::write_line("Slot 1: %1,%2", p1, p2);
}
void slot_function2(int p1, int p2)
{
	clan::Console::write_line("Slot 2: %1,%2", p1, p2);
}

int main(const std::vector<std::string> &args){ 

	SetupCore setup_core;
	SetupDisplay setup_display; 
	SetupGL setup_gl;

	ConsoleWindow console_window("Console");

	//initialTests();
	
	DisplayWindow window("", 1024, 768); 

	Canvas canvas(window); 
	InputDevice keyboard = window.get_ic().get_keyboard(); 	
	
	ObjectBase* obj1 = new ObjectBase(1, "obj1");
	StubBehavior* b1 = new StubBehavior(1, "move");
	ControllerBase* c = new ControllerBase(obj1);
	c->addBehavior(b1);
	c->startBehaviors();

	ObjectBase* obj2 = new ObjectBase(2, "obj2");
	StubBehavior* b2 = new StubBehavior(2, "move");
	ControllerBase* c2 = new ControllerBase(obj2);
	c2->addBehavior(b2);
	c2->startBehaviors();

	GameTime gameTime(60, 60);
	while (!keyboard.get_keycode(keycode_escape)) { 
		canvas.clear(Colorf::white);
	
		gameTime.update();
		c->doBehaviorsStep(gameTime.get_time_elapsed_ms());
		c2->doBehaviorsStep(gameTime.get_time_elapsed_ms());

		canvas.flush();
		window.flip();
		KeepAlive::process();
	}	
	return 0; 
}

Application app(&main);

void initialTests()
{
	ObjectBase* obj1 = new ObjectBase();
	obj1->setId(1);
	obj1->setName("obj1");
	Console::write_line(string(*obj1));

	ObjectBase* obj2 = new ObjectBase(2, "obj2");
	Console::write_line(string(*obj2));

	Console::write_line("are n equal: " + to_string((long long)(*obj1 == *obj2)));
	Console::write_line("are equal: " + to_string((long long)(*obj1 == *obj1)));
	
	BehaviorBase* b1 = new BehaviorBase(1, "move");
	b1->doStep(17);
	b1->onInteraction(obj1, obj2);

	BehaviorBase* b2 = new BehaviorBase(2, "shoot");
	
	Console::write_line("are n equal: " + to_string((long long)(*b1 == *b2)));
	Console::write_line("are equal: " + to_string((long long)(*b1 == *b1)));

	ControllerBase* c = new ControllerBase(obj1);
	c->addBehavior(b1);
	c->addBehavior(b2);

	c->removeBehavior(b2);

	StubBehavior* b3 = new StubBehavior(3, "cry");
	Console::write_line(b3->getClassName());
	c->addBehavior(b3);

	c->startBehaviors(StubBehavior::GetClassName());
	Console::write_line(string(*c));
	
	delete obj2;
	delete b2;
	delete c;
}