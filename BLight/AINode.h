#pragma once
#include "stdafx.h"
#include "AIBlackboard.h"

// TODO: make virtual
class AINode
{
public:
	AINode(void);
	AINode(AIBlackboard*);
	
	~AINode(void);

	virtual bool run(){return true;}

	virtual vector<AINode*>& getChildren(){return children;}

protected:
	vector<AINode*> children;
	AIBlackboard* blackboard;
};

