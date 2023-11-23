#include "PhysicWorld.h"

PhysicWorld::PhysicWorld(sf::Vector2f gravity)
	:  world(b2Vec2(gravity.x, gravity.y)) {}

void PhysicWorld::addObject(std::shared_ptr<BaseObject> objectToAdd, bool makeDynamic)
{
	// check if object already exists in the world
	for (int i = 0; i < renderObjects.size(); i++)
	{
		if (objectToAdd == renderObjects[i])
			return;
	}
	
	// add object
	renderObjects.push_back(objectToAdd);

	// add to the world
	objectToAdd->update();

	if (!makeDynamic)
	{
		// create a static body
		createStaticBody(objectToAdd, 0, 0);
	}
	else
	{
		// create a dynamic body
		createDynamicBody(objectToAdd, 1.f, 0.3f);
	}
}

void PhysicWorld::removeObject(const std::shared_ptr<BaseObject> objectToRemove)
{
	// find the object to remove
	for (int i = 0; i < renderObjects.size(); i++)
	{
		if (objectToRemove == renderObjects[i])
		{
			// remove object
			int position = std::distance(renderObjects.begin(), renderObjects.begin() + i);
			renderObjects.erase(renderObjects.begin() + i);
			b2Bodys.erase(b2Bodys.begin() + position);
		}
	}
}

void PhysicWorld::setGravity(sf::Vector2f gravity)
{
	world.SetGravity(b2Vec2(gravity.x, gravity.y));
}

void PhysicWorld::update()
{
	if (renderObjects.size() != b2Bodys.size())
	{
		std::cout << "Error trying to update the Physic. Number of objects does not match the number of simulated bodys." << std::endl;
		return;
	}

	accumulatedTime += time.reset().asSeconds();
	while (accumulatedTime >= timeStep)
	{
		world.Step(timeStep, velocityIterations, positionIterations);
		accumulatedTime -= timeStep;
	}

	for (unsigned int i = 0; i < renderObjects.size(); i++)
	{
		// get new position and angle from Block2D
		b2Vec2 position = b2Bodys[i]->GetPosition();
		float angle = b2Bodys[i]->GetAngle();

		// update the SFML Object
		renderObjects[i]->position = sf::Vector2f(position.x, position.y);
		renderObjects[i]->rotationAngle = angle * 180.f / b2_pi;
	}
}

void PhysicWorld::createStaticBody(std::shared_ptr<BaseObject> objectToAdd, float density, float friction)
{
	b2BodyDef staticBodyDef;
	staticBodyDef.position.Set(objectToAdd->position.x, objectToAdd->position.y);
	b2Body* staticBody = world.CreateBody(&staticBodyDef);
	b2Bodys.push_back(staticBody);
	b2PolygonShape staticBox;
	staticBox.SetAsBox(objectToAdd->getSize().x / 2, objectToAdd->getSize().y / 2);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &staticBox;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	staticBody->CreateFixture(&fixtureDef);
}

void PhysicWorld::createDynamicBody(std::shared_ptr<BaseObject> objectToAdd, float density, float friction)
{
	b2BodyDef dynamicBodyDef;
	dynamicBodyDef.type = b2_dynamicBody;
	dynamicBodyDef.position.Set(objectToAdd->position.x, objectToAdd->position.y);
	b2Body* dynamicBody = world.CreateBody(&dynamicBodyDef);
	b2Bodys.push_back(dynamicBody);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(objectToAdd->getSize().x / 2.f, objectToAdd->getSize().y / 2.f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	dynamicBody->CreateFixture(&fixtureDef);
}