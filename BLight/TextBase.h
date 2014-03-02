#pragma once
#include "stdafx.h"
#include "CustomPoint.h"

class TextBase
{
public:
	TextBase(void);
	TextBase(string, string);
	
	~TextBase(void);

	string getText()  { return text; }
	void setText(string val) { text = val; }

	string getFont()  { return font; }
	void setFont(string val) { font = val; }

	int getCharacterSize()  { return characterSize; }
	void setCharacterSize(int val) { characterSize = val; }

	CustomPoint* getPosition()  { return &position; }
	void setPosition(CustomPoint* val) { position = *val; }

protected:
	void init(string = "no text", string = "tahoma");

	string text;
	string font;
	
	int characterSize;

	CustomPoint position;
};

