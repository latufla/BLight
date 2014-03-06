#include "PopupText.h"


PopupText::PopupText(void)
{
	alphaStep = -5;
	positionStep = 0.01f;
}


PopupText::~PopupText(void)
{
}

void PopupText::draw()
{	
	if(alpha > 0){
		alpha += alphaStep;
		position.y += positionStep;	
		__super::draw();	
	}
}
