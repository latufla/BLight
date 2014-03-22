#include "PopupText.h"


PopupText::PopupText(void) : TextBase()
{
	alphaStep = 5;
	positionStep.set(0.0f, -0.01f);

	toDestroy = false;
}

PopupText::~PopupText(void)
{
	
}

void PopupText::draw()
{
	if(alpha <= 0){
		toDestroy = true;
		return;
	}

	alpha -= alphaStep;
	position.x -= positionStep.x;
	position.y -= positionStep.y;

	__super::draw();	
}
