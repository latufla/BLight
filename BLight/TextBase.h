#pragma once
#include "stdafx.h"
#include "CustomPoint.h"
#include "IDrawable.h"

class TextBase : public IDrawable
{
public:
	TextBase(void);
	TextBase(string, string);
	
	~TextBase(void);

	virtual void draw();

	string getText()  { return text; }
	void setText(string val) { text = val; }

	string getFont()  { return font; }
	void setFont(string val) { font = val; }

	int getColor() const { return color; }
	void setColor(int val) { color = val; }

	int getAlpha() const { return alpha; }
	void setAlpha(int val) { alpha = val; }

	int getCharacterSize()  { return characterSize; }
	void setCharacterSize(int val) { characterSize = val; }
	
	CustomPoint& getPosition(){return position;}

protected:
	void init(string = "no text", string = "tahoma");

	string text;
	string font;
	
	int color;
	int alpha;
	int characterSize;

	CustomPoint position;
};

