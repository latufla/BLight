#pragma once
#include "ClanLib\Core\System\game_time.h"

using namespace clan;

class GameTimer
{
public:
	GameTimer(void);
	GameTimer(int, int);
	~GameTimer(void);
	
	int update();
	int getElapsedTimeMs() const;

protected:
	void init(int = 60, int = 60);

	GameTime* timer;
};

