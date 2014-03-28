#pragma once
#include "BehaviorBase.h"
#include "ControlBehavior.h"
#include "AttackCommand.h"

class AttackBehavior : public BehaviorBase
{
public:
	AttackBehavior(void);
	~AttackBehavior(void);

	BehaviorBase* clone();

	BehaviorType getType(){return ATTACK_BEHAVIOR;}

protected:
	bool doStep(int);
	void showPopup(ControllerBase* c);
	
	int damage;
};

