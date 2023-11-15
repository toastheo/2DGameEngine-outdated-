#include "GameEngine.h"

GameEngine::GameEngine()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window.create(sf::VideoMode(1600, 900, desktop.bitsPerPixel), "2D Game Engine", sf::Style::Default);
}

GameEngine::~GameEngine()
{
	// not implemented
}

void GameEngine::update()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	window.clear();
	window.display();
}

bool GameEngine::isRunning()
{
	return window.isOpen();
}
