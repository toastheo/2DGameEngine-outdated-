#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

class Scene
{
public:
	Scene();
	~Scene();

	void load(std::shared_ptr<sf::RenderWindow> target);

private:
	void update();
	void render();

	std::shared_ptr<sf::RenderWindow> target;
};

