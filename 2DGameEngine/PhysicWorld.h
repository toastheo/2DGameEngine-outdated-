#pragma once
#include "BaseObject.h"
#include "box2d/box2d.h"
#include <iostream>

class PhysicWorld
{
public:
	PhysicWorld(sf::Vector2f gravity = sf::Vector2f(0.f, 100.f));
	~PhysicWorld() {};

	void addObject(std::shared_ptr<BaseObject> objectToAdd, bool makeDynamic = true);
	void removeObject(const std::shared_ptr<BaseObject> objectToRemove);

	void setGravity(sf::Vector2f gravity);

	void update();

private:
	std::vector<std::shared_ptr<BaseObject>> renderObjects;			///< Stores all the SFML created objects to render on the screen.

	b2World world;
	std::vector<b2Body*> b2Bodys;

	const float timeStep = 1.f / 60.f;
	const int32 velocityIterations = 6;
	const int32 positionIterations = 2;

	void setOriginToCenter(std::shared_ptr<BaseObject> object);		// DOES NOT WORK CORRECTLY FIX THIS!
	void createStaticBody(std::shared_ptr<BaseObject> objectToAdd, float density, float friction);
	void createDynamicBody(std::shared_ptr<BaseObject> objectToAdd, float density, float friction);
};

