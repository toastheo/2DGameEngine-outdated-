#include "PhysicWorld.h"

PhysicWorld::PhysicWorld(sf::Vector2f gravity)
	:  world(b2Vec2(gravity.x, gravity.y)) {}

void PhysicWorld::addObject(std::shared_ptr<BaseObject> objectToAdd, bool makeDynamic)
{
	// check if object already exists in the world
	auto it = std::find_if_not(renderObjects.begin(), renderObjects.end(),
		[&objectToAdd](const std::shared_ptr<BaseObject>& obj) {
			return obj.get() == objectToAdd.get();
		});

	// if not
	if (it == renderObjects.end())
	{
		// add object
		renderObjects.push_back(objectToAdd);

		// change origin to center (for correct transformations) without changing the current position
		//setOriginToCenter(objectToAdd);

		// add to the world
		if (!makeDynamic)
		{
			// create a static body
			createStaticBody(objectToAdd, 0, 0);
		}
		else
		{
			// create a dynamic body
			createDynamicBody(objectToAdd, 1.f, 0.3);
		}
	}
}

void PhysicWorld::removeObject(const std::shared_ptr<BaseObject> objectToRemove)
{
	// find the object to remove
	auto it = std::find_if(renderObjects.begin(), renderObjects.end(),
		[&objectToRemove](const std::shared_ptr<BaseObject>& obj) {
			return obj.get() == objectToRemove.get();
		});

	// remove object
	if (it != renderObjects.end())
	{
		int position = std::distance(renderObjects.begin(), it);
		renderObjects.erase(it);
		b2Bodys.erase(b2Bodys.begin() + position);
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

	world.Step(timeStep, velocityIterations, positionIterations);

	for (int i = 0; i < renderObjects.size(); i++)
	{
		// get new position and angle from Block2D
		b2Vec2 position = b2Bodys[i]->GetPosition();
		float angle = b2Bodys[i]->GetAngle();

		// update the SFML Object
		renderObjects[i]->position = sf::Vector2f(position.x, position.y);
		renderObjects[i]->rotationAngle = angle * 180.f / b2_pi;
	}
}

void PhysicWorld::setOriginToCenter(std::shared_ptr<BaseObject> object)
{
	sf::FloatRect bounds = object->getGlobalBounds();
	sf::Vector2f center(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);

	// calculate difference between current origin and middle point
	sf::Vector2f originDiff = center - object->origin;

	// set new origin
	object->origin = center;

	// maintain the original position
	object->position = object->position + originDiff;
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
	dynamicBox.SetAsBox(objectToAdd->getSize().x / 2, objectToAdd->getSize().y / 2);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	dynamicBody->CreateFixture(&fixtureDef);
}