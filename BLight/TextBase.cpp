#include "TextBase.h"
#include "EngineConnector.h"


TextBase::TextBase(void)
{
	init();
}

TextBase::TextBase(string text, string font)
{
	init(text, font);
}


TextBase::~TextBase(void)
{
}

void TextBase::init(string text, string font)
{
	this->text = text;
	this->font = font;

	color = 0x0000FF;
	alpha = 255;
	
	characterSize = 18;

	position.x = 5.0f;
	position.y = 5.0f;
}

void TextBase::draw()
{
	EngineConnector::drawText(this);
}
