#include "Scene.h"

Scene::Scene()
{
	targetWin = nullptr;
}

Scene::~Scene()
{
	// nothing to do here
}

void Scene::load(std::shared_ptr<sf::RenderWindow> target)
{
	this->targetWin = target;

	update();
	render();

	this->targetWin = nullptr;
}
