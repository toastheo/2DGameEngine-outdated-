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
	try
	{
		if (!startedSceneLoop)
		{
			startedSceneLoop = true;
			init();
		}

		this->targetWin = target;

		update();
		render();
	}
	catch (...)
	{
		std::cout << "Error trying to load the scene." << std::endl;
	}
}
