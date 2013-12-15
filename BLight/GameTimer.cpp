#include "GameTimer.h"


GameTimer::GameTimer(void)
{
	init();
}

GameTimer::GameTimer(int ticksPerSecond = 60, int maxUpdatesPerSecond = 60)
{
	init(ticksPerSecond, maxUpdatesPerSecond);
}

GameTimer::~GameTimer(void)
{
}

void GameTimer::init(int ticksPerSecond, int maxUpdatesPerSecond)
{
	timer = new GameTime(ticksPerSecond, maxUpdatesPerSecond);
}

int GameTimer::update()
{
	timer->update();
	return getElapsedTimeMs();
}

int GameTimer::getElapsedTimeMs() const
{
	return timer->get_time_elapsed_ms();
}

