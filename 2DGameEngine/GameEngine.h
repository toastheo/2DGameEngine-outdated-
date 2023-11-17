#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>
#include "Scene.h"
#include "TestSzene.h"

class GameEngine
{
public:
	GameEngine(bool verticalSyncEnabled = false);
	~GameEngine();

	void update();
	bool isRunning();

private:
	std::shared_ptr<sf::RenderWindow> window;
	std::thread thread;
	std::atomic<bool> running = true;
	bool verticalSync;
	int antialiasingLevel = 8;

	void renderThread();

	TestSzene testSzene;
};

