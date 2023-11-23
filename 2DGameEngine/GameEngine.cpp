#include "GameEngine.h"

GameEngine::GameEngine(bool verticalSync)
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window = std::make_shared<sf::RenderWindow>();
	sf::ContextSettings settings;
	settings.antialiasingLevel = antialiasingLevel;

	window->create(sf::VideoMode(1600, 900, desktop.bitsPerPixel), "2D Game Engine", sf::Style::Default, settings);
	window->setVerticalSyncEnabled(verticalSync);
}

GameEngine::~GameEngine()
{
	if (thread.joinable())
	{
		thread.join();
	}
}

void GameEngine::update()
{
	if (!scenePtr)
	{
		std::cout << "Scene Pointer is empty. Make sure to load a scene before starting the Game Engine.\nClosing window." << std::endl;
		window->close();
		return;
	}

	if (!threadStarted)
	{
		thread = std::thread(&GameEngine::renderThread, this);
		threadStarted = true;
	}

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
	if (!scenePtr)
		return;

	window->setActive(true);

	while (running && window->isOpen())
	{
		window->clear();
		scenePtr->load(window);
		window->display();
	}
}