#include "SpriteObject.h"

SpriteObject::SpriteObject(sf::Vector2f position, float rotationAngle, sf::Vector2f scale, bool isVisible, bool isActive)
	: BaseObject(position, rotationAngle, scale, isVisible, isActive)
{
	texture = std::make_shared<sf::Texture>();
}

void SpriteObject::setTexture(std::shared_ptr<sf::Texture> texture, bool smoothing, bool repeat)
{
	this->texture = texture;

	if (smoothing)
		texture->setSmooth(smoothing);

	if (repeat)
		texture->setRepeated(repeat);

	sprite.setTexture(*texture);
	size = sprite.getLocalBounds().getSize();
}

void SpriteObject::setTextureRect(sf::IntRect textureRect)
{
	sprite.setTextureRect(textureRect);
}

void SpriteObject::flipX()
{
	scale = sf::Vector2f(-scale.x, scale.y);
	position = sf::Vector2f(position.x + sprite.getLocalBounds().width * -scale.x, position.y);
}

void SpriteObject::flipY()
{
	scale = sf::Vector2f(scale.x, -scale.y);
	position = sf::Vector2f(position.x, position.y + sprite.getLocalBounds().height * -scale.y);
}

void SpriteObject::setOrigin(OriginPos pos)
{
	switch (pos) 
	{
	case OriginPos::UpLeft:
		origin = sf::Vector2f(0, 0);
		break;

	case OriginPos::UpRight:
		origin = sf::Vector2f(size.x, 0);
		break;

	case OriginPos::DownLeft:
		origin = sf::Vector2f(0, size.y);
		break;

	case OriginPos::DownRight:
		origin = sf::Vector2f(size);
		break;

	case OriginPos::Center:
		origin = sf::Vector2f(size.x / 2, size.y / 2);
		break;
	}
}

const void SpriteObject::render(std::shared_ptr<sf::RenderWindow> targetWin) const
{
	if (isVisible && isActive)
		targetWin->draw(sprite);
}

void SpriteObject::update()
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