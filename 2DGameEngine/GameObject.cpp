#include "GameObject.h"

GameObject::GameObject(sf::Vector2f position, float rotationAngle, sf::Vector2f scale, bool isVisible, bool isActive)
{
	texture = std::make_shared<sf::Texture>();

	this->position = position;
	this->rotationAngle = rotationAngle;
	this->scale = scale;
	this->isVisible = isVisible;
	this->isActive = isActive;

	size = sf::Vector2f(0, 0);
	color = sf::Color::White;
	origin = sf::Vector2f(0, 0);
	motionVector = sf::Vector2f(0.f, 0.f);
	rotationVector = 0.f;
	scalingVector = sf::Vector2f(0.f, 0.f);
}

GameObject::~GameObject()
{
	// not necessary
}

void GameObject::setTexture(std::shared_ptr<sf::Texture> texture, bool smoothing, bool repeat)
{
	this->texture = texture;

	if (smoothing)
		texture->setSmooth(smoothing);

	if (repeat)
		texture->setRepeated(repeat);

	sprite.setTexture(*texture);
	size = sprite.getLocalBounds().getSize();
}

void GameObject::setTextureRect(sf::IntRect textureRect)
{
	sprite.setTextureRect(textureRect);
}

void GameObject::setOrigin(OriginPos pos)
{
	switch (pos) 
	{
	case OriginPos::UpLeft:
		sprite.setOrigin(0, 0);
		break;

	case OriginPos::UpRight:
		sprite.setOrigin(size.x, 0);
		break;

	case OriginPos::DownLeft:
		sprite.setOrigin(0, size.y);
		break;

	case OriginPos::DownRight:
		sprite.setOrigin(size);
		break;

	case OriginPos::Center:
		sprite.setOrigin(size.x / 2, size.y / 2);
		break;
	}

	origin = sprite.getOrigin();
}

sf::Vector2f GameObject::getSize()
{
	return size;
}

void GameObject::render(std::shared_ptr<sf::RenderWindow> target)
{
	if (isVisible && isActive)
		target->draw(sprite);
}

void GameObject::update()
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

	sprite.setPosition(position);
	sprite.setRotation(rotationAngle);
	sprite.setScale(scale);
	sprite.setColor(color);
	sprite.setOrigin(origin);

	if (motionVector != sf::Vector2f(0.f, 0.f)) 
	{
		sprite.move(motionVector.x * elapsedTime, motionVector.y * elapsedTime);
		position = sprite.getPosition();
	}

	if (rotationVector != 0.f)
	{
		sprite.rotate(rotationVector * elapsedTime);
		rotationAngle = sprite.getRotation();
	}

	if (scalingVector != sf::Vector2f(0.f, 0.f))
	{
		sprite.scale(scalingVector * elapsedTime);
		scale = sprite.getScale();
	}

	behaviour();
}