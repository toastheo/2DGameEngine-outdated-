#pragma once
#include <SFML/Graphics.hpp>

class GameTime
{
public:
	GameTime();
	~GameTime() {};

	sf::Time getTotalLiveTime() const;
	float getDeltaTime();
	sf::Time reset();

private:
	sf::Clock clock;
	sf::Time lastFrameTime;
	sf::Time deltaTime;
};

