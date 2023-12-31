#include "CircleShapeObject.h"

CircleShapeObject::CircleShapeObject(sf::Vector2f position, float rotationAngle, sf::Vector2f scale, bool isVisible, bool isActive)
	: BaseObject(position, rotationAngle, scale, isVisible, isActive)
{
	shape = sf::CircleShape(80.f, 4);
	outlineThickness = 0.f;
	outlineColor = sf::Color::Black;
	size = shape.getLocalBounds().getSize();
	texture = std::make_shared<sf::Texture>();
}

void CircleShapeObject::update()
{
	float elapsedTime = time.getDeltaTime();

	if (!loopStarted)
	{
		start();
		elapsedTime = 0;
		loopStarted = true;
	}

	if (!isActive)
		return;

	shape.setOutlineThickness(outlineThickness);
	shape.setOutlineColor(outlineColor);

	shape.setPosition(position);
	lastPos = position;

	shape.setRotation(rotationAngle);
	shape.setScale(scale);
	size = shape.getGlobalBounds().getSize();
	shape.setFillColor(color);

	if (motionVector != sf::Vector2f(0.f, 0.f))
	{
		shape.move(motionVector.x * elapsedTime, motionVector.y * elapsedTime);
		position = shape.getPosition();
	}

	if (rotationVector != 0.f)
	{
		shape.rotate(rotationVector * elapsedTime);
		rotationAngle = shape.getRotation();
	}

	if (scalingVector != sf::Vector2f(0.f, 0.f))
	{
		shape.scale(scalingVector * elapsedTime);
		scale = shape.getScale();
	}

	behaviour();
}

void CircleShapeObject::render (std::shared_ptr<sf::RenderWindow> targetWin) const
{
	if (isVisible && isActive)
		targetWin->draw(shape);
}

void CircleShapeObject::setTexture(std::shared_ptr<sf::Texture> texture, bool smoothing, bool repeat)
{
	this->texture = texture;

	if (smoothing)
		texture->setSmooth(smoothing);

	if (repeat)
		texture->setRepeated(repeat);

	shape.setTexture(texture.get());
}

void CircleShapeObject::setTextureRect(sf::IntRect textureRect)
{
	shape.setTextureRect(textureRect);
}

void CircleShapeObject::defineShape(float radius, unsigned int numberOfPoints)
{
	shape.setRadius(radius);
	shape.setPointCount(numberOfPoints);
	size = shape.getLocalBounds().getSize();
	globalBounds = shape.getGlobalBounds();
}

void CircleShapeObject::defineShape(float radius, Shapes shape)
{
	this->shape.setRadius(radius);

	switch (shape)
	{
	case Shapes::Circle:
		this->shape.setPointCount(30);
		break;

	case Shapes::Triangle:
		this->shape.setPointCount(3);
		break;

	case Shapes::Square:
		this->shape.setPointCount(4);
		break;

	case Shapes::Octagon:
		this->shape.setPointCount(8);
		break;
	}

	size = this->shape.getLocalBounds().getSize();
	globalBounds = this->shape.getGlobalBounds();
}
