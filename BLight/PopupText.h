#pragma once
#include "TextBase.h"

class PopupText : public TextBase
{
public:
	PopupText(void);
	~PopupText(void);

	void draw();

	bool getToDestroy() const { return toDestroy; }

protected:
	int alphaStep;
	CustomPoint positionStep;

	bool toDestroy;
};

