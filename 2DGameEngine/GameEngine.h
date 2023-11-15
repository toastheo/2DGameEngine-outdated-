#pragma once
#include <SFML/Graphics.hpp>

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void update();
	bool isRunning();
private:
	sf::RenderWindow window;
};

