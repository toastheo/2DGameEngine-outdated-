#include "GameEngine.h"

GameEngine::GameEngine(bool verticalSync)
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window = std::make_shared<sf::RenderWindow>();
	window->create(sf::VideoMode(1600, 900, desktop.bitsPerPixel), "2D Game Engine", sf::Style::Default);
	window->setVerticalSyncEnabled(verticalSync);

	thread = std::thread(&GameEngine::renderThread, this);
}

GameEngine::~GameEngine()
{
	// not necessary
}

void GameEngine::update()
{
	window->setActive(false);

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			running = false;

			if (thread.joinable())
			{
				thread.join();
			}

			window->close();
		}
	}
}

bool GameEngine::isRunning()
{
	return window->isOpen();
}

void GameEngine::renderThread()
{
	window->setActive(true);

	while (running && window->isOpen())
	{
		window->clear();
		window->display();
	}
}