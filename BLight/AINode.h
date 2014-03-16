#pragma once
#include "stdafx.h"

// TODO: make virtual
class AINode
{
public:
	AINode(void);
	~AINode(void);

	virtual bool run(){return true;}

protected:
	vector<AINode*> children;
};

