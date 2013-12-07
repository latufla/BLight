#include "ViewBase.h"
#include "ClanLib\GL\opengl_target.h"
#include "ClanLib\Core\Text\console.h"


ViewBase::ViewBase(void)
{
}


ViewBase::~ViewBase(void)
{
}

void ViewBase::update( ObjectBase* obj)
{
	clan::Console::write_line("update view for: " + string(*obj));
}
