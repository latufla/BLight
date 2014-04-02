#pragma once
#include "BehaviorBase.h"

class BehaviorsFactory
{
public:
	static BehaviorBase* create(string);
};

