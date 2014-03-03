#pragma once
#include "stdafx.h"
#include "TextBase.h"

class PopupText : public TextBase
{
public:
	PopupText(void);
	~PopupText(void);

	void draw();

protected:
	int alphaStep;
	float positionStep;
};

