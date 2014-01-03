#pragma once

#include "stdafx.h"
#include "ObjectBase.h"
#include <functional>

class ViewBase
{
public:
	ViewBase(void);
	~ViewBase(void);

	void update(ObjectBase*);
	std::function<void(EventDispatcher*)> updateListener;
};

