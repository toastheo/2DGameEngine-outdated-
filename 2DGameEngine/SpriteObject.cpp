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
	globalBounds = sf::FloatRect(sprite.getTextureRect().left, sprite.getTextureRect().top, sprite.getTextureRect().width, sprite.getTextureRect().height);
	sprite.setOrigin(sprite.getGlobalBounds().getSize().x / 2.f, sprite.getGlobalBounds().getSize().y / 2.f);
}

void SpriteObject::setTextureRect(sf::IntRect textureRect)
{
	sprite.setTextureRect(textureRect);
	sprite.setOrigin(sprite.getGlobalBounds().getSize().x / 2.f, sprite.getGlobalBounds().getSize().y / 2.f);
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

void SpriteObject::render(std::shared_ptr<sf::RenderWindow> targetWin) const
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
	lastPos = position;

	sprite.setRotation(rotationAngle);
	sprite.setScale(scale);
	size = sprite.getGlobalBounds().getSize();
	sprite.setColor(color);

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