#include "TextBase.h"
#include "Config.h"


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
}

void TextBase::draw()
{
	Config::engine->drawText(this);
}
