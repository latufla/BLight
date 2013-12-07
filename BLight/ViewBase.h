#pragma once

#include "stdafx.h"
#include "ObjectBase.h"

class ViewBase
{
public:
	ViewBase(void);
	~ViewBase(void);

	void update(ObjectBase*);
};

