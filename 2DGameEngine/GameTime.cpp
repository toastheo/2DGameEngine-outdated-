#include "GameTime.h"

GameTime::GameTime()
{
	lastFrameTime = sf::Time::Zero;
	deltaTime = sf::Time::Zero;
}

sf::Time GameTime::getTotalLiveTime() const
{
	return clock.getElapsedTime();
}

float GameTime::getDeltaTime()
{
	sf::Time now = clock.getElapsedTime();
	deltaTime = now - lastFrameTime;
	lastFrameTime = now;

	return deltaTime.asSeconds();
}

sf::Time GameTime::reset()
{
	return clock.restart();
}
