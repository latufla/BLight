#pragma once
#include "Info.h"
#include "CustomPoint.h"

class SpawnerBehaviorInfo : public Info
{
public:
	SpawnerBehaviorInfo(void);
	~SpawnerBehaviorInfo(void);

	int intervalMSec;
	int chance;
	string creature;
	float spawnX;
	float spawnY;

	void update(string name, int val){
		if(name == "intervalMSec")
			intervalMSec = val;
		else if(name == "chance")
			chance = val;
	}

	void update(string name, float val){
		if(name == "spawnX")
			spawnX = val;
		else if(name == "spawnY")
			spawnY = val;
	}

	void update(string name, string val){
		if(name == "creature")
			creature = val;
	};


};

