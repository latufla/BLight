#include "PopupText.h"

PopupText::PopupText(void) : alphaStep(-5), positionStep(0.01f)
{
	SceneController::getInstance().addChild((TextBase*)this);	
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
	} else {
		//SceneController::getInstance().removeChild(this);			
	}
}
