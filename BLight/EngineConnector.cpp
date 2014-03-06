#include "EngineConnector.h"

const int EngineConnector::FPS = 60;

const int EngineConnector::MUL_X = 20;
const int EngineConnector::MUL_Y = 20;
const int EngineConnector::SCALE_X = 1;
const int EngineConnector::SCALE_Y = -1;

const int EngineConnector::WINDOW_W = 1024;
const int EngineConnector::WINDOW_H = 768;

void EngineConnector::init( void(*mainLoop)(int) )
{
	ContextSettings settings;
	settings.antialiasingLevel = 0;
	window = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H), "", Style::Default, settings);
	window->setFramerateLimit(FPS);

	sf::Font font;
	font.loadFromFile("fonts/tahoma.ttf");
	fonts["tahoma"] = font;

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
	static Event event;
	while (window->pollEvent(event)){
		if (event.type == Event::Closed)
			return true;
	}
	return false;
}

Int32 EngineConnector::shouldDoStep( Clock& timer)
{
	Int32 time = timer.getElapsedTime().asMilliseconds();
	timer.restart();
	return time;
}

void EngineConnector::drawPoint(CustomPoint p)
{
	static CircleShape c(0);
	
	c.setRadius(2);
	
	c.setOrigin(2, 2);

	applyAxises(&p);
	c.setPosition(p.x, p.y);

	c.setFillColor(Color::Blue);
	window->draw(c);
}


void EngineConnector::drawLine(CustomPoint b, CustomPoint e)
{
	applyAxises(&b);
	applyAxises(&e);

	static VertexArray line(Lines, 2);
	
	line[0].position.x = b.x; 
	line[0].position.y = b.y;
	line[0].color = Color::Magenta;

	line[1].position.x = e.x; 
	line[1].position.y = e.y; 
	line[1].color = Color::Magenta;

	window->draw(line);
}


void EngineConnector::applyAxises( CustomPoint* outPoint)
{
	outPoint->x = outPoint->x * MUL_X * SCALE_X;
	outPoint->y = outPoint->y * MUL_Y * SCALE_Y + WINDOW_H;
}

void EngineConnector::declineAxises( CustomPoint* outPoint)
{
	outPoint->x = (outPoint->x / MUL_X) / SCALE_X;
	outPoint->y = ((outPoint->y - WINDOW_H) / MUL_Y) / SCALE_Y;
}


void EngineConnector::drawShape(CustomPolygon* poly)
{
	vector<CustomPoint>* vxs = poly->getVertexes();
	for (auto it = vxs->cbegin(); it != vxs->cend() - 1; it++){
		EngineConnector::drawLine(*it, *(it + 1));
	}
	EngineConnector::drawLine(*vxs->cbegin(), *(vxs->cend() - 1));
}

void EngineConnector::drawShape(CustomCircle* circle)
{
	static CircleShape c(0);
	
	c.setRadius(circle->getRadius() * MUL_X);
	
	CustomPoint* origin = circle->getOrigin();
	c.setOrigin(origin->x * MUL_X, origin->y * MUL_Y);

	static CustomPoint pos;
	pos.set(*circle->getPosition());
	applyAxises(&pos);
	c.setPosition(pos.x, pos.y);

	c.setOutlineThickness(1);
	c.setOutlineColor(Color::Blue);
	window->draw(c);
}

bool EngineConnector::isLeftMouseButtonPressed()
{
	return Mouse::isButtonPressed(Mouse::Left);
}

CustomPoint* EngineConnector::getMousePosition()
{
	Vector2i* pos = &Mouse::getPosition(*window);
	static CustomPoint res;
	res.set((float)pos->x, (float)pos->y);
	declineAxises(&res);
	return &res;	
}

void EngineConnector::drawText(TextBase* text)
{
	static Text t;

	t.setString(text->getText());
	t.setFont(fonts[text->getFont()]);
	t.setCharacterSize(text->getCharacterSize());
	
	static CustomPoint pos;
	pos.set(*text->getPosition());
	applyAxises(&pos);
	t.setPosition(pos.x, pos.y);	

	t.setStyle(Text::Regular);
	
	int c = text->getColor();
	static Color color;
	color.r = (c >> 16) & 0xFF;
	color.g = (c >> 8) & 0xFF;
	color.b = c & 0xFF;
	color.a = text->getAlpha();
	t.setColor(color);

	window->draw(t);
}






