#include "Scene.h"

Scene::Scene()
{
	target = nullptr;
}

Scene::~Scene()
{
	// nothing to do here
}

void Scene::load(std::shared_ptr<sf::RenderWindow> target)
{
	this->target = target;

	update();
	render();

	this->target = nullptr;
}

void Scene::update()
{
	
}

void Scene::render()
{
	
}
