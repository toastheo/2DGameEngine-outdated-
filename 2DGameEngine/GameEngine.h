#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void update();
	bool isRunning();

private:
	std::shared_ptr<sf::RenderWindow> window;
	Scene gameScene;
};

