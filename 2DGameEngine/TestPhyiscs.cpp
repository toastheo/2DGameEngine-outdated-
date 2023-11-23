#include "TestPhyiscs.h"

void TestPhyiscs::init()
{
	// init ground as static
	if (!ground_tex->loadFromFile("ground.jpg"))
	{
		std::cout << "Error trying to load ground.jpg" << std::endl;
	}
	ground->setTexture(ground_tex);
	ground->position += sf::Vector2f(ground->getSize().x / 2.f, ground->getSize().y / 2.f);
	ground->position.y += 700.f;

	ground2->setTexture(ground_tex);
	ground2->position = sf::Vector2f(ground->position.x + ground->getSize().x, ground->position.y);

	ground3->setTexture(ground_tex);
	ground3->position = sf::Vector2f(ground2->position.x + ground->getSize().x, ground->position.y);

	pWorld.addObject(ground, false);
	pWorld.addObject(ground2, false);
	pWorld.addObject(ground3, false);

	// init chicken as dynamic
	if (!chicken_tex->loadFromFile("BlueChickenIdle-Sheet.png"))
	{
		std::cout << "Error trying to load BlueChickenIdle-Sheet.png" << std::endl;
	}
	chicken->setTexture(chicken_tex);
	chicken->setTextureRect(sf::IntRect(0, 0, chicken->getSize().x / 5, chicken->getSize().y));
	chicken->position.x += 500;
	chicken->scale = sf::Vector2f(7.f, 7.f);

	pWorld.addObject(chicken);
}

void TestPhyiscs::update()
{
	ground->update();
	ground2->update();
	ground3->update();
	chicken->update();
	pWorld.update();
}

void TestPhyiscs::render() const
{
	ground->render(targetWin);
	ground2->render(targetWin);
	ground3->render(targetWin);
	chicken->render(targetWin);
}
