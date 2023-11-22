#include "BaseObject.h"

BaseObject::BaseObject(sf::Vector2f position, float rotationAngle, sf::Vector2f scale, bool isVisible, bool isActive)
{
	this->position = position;
	this->rotationAngle = rotationAngle;
	this->scale = scale;
	this->isVisible = isVisible;
	this->isActive = isActive;

	size = sf::Vector2f(0, 0);
	globalBounds = sf::FloatRect(0.f, 0.f, 0.f, 0.f);
	color = sf::Color::White;
	origin = sf::Vector2f(0, 0);
	motionVector = sf::Vector2f(0.f, 0.f);
	rotationVector = 0.f;
	scalingVector = sf::Vector2f(0.f, 0.f);
}

sf::Vector2f BaseObject::getSize() const
{
	return size;
}

sf::FloatRect BaseObject::getGlobalBounds() const
{
	return globalBounds;
}
