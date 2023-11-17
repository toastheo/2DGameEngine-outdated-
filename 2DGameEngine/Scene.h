#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
#include "GameTime.h"

class Scene
{
public:
	Scene();
	~Scene();

	void load(std::shared_ptr<sf::RenderWindow> targetWin);

protected:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	std::shared_ptr<sf::RenderWindow> targetWin;
	bool startedSceneLoop = false;
};

