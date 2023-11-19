#include "TextObject.h"

TextObject::TextObject(sf::Vector2f position, float rotationAngle, sf::Vector2f scale, bool isVisible, bool isActive)
	: BaseObject(position, rotationAngle, scale, isVisible, isActive)
{
	characterSizeInPixel = 11;
	style = sf::Text::Style::Regular;
}

void TextObject::update()
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

	text.setString(string);
	text.setCharacterSize(characterSizeInPixel);
	text.setStyle(style);
	text.setPosition(position);
	text.setRotation(rotationAngle);
	text.setScale(scale);
	text.setFillColor(color);
	text.setOrigin(origin);

	if (motionVector != sf::Vector2f(0.f, 0.f))
	{
		text.move(motionVector.x * elapsedTime, motionVector.y * elapsedTime);
		position = text.getPosition();
	}

	if (rotationVector != 0.f)
	{
		text.rotate(rotationVector * elapsedTime);
		rotationAngle = text.getRotation();
	}

	if (scalingVector != sf::Vector2f(0.f, 0.f))
	{
		text.scale(scalingVector * elapsedTime);
		scale = text.getScale();
	}

	behaviour();
}

const void TextObject::render(std::shared_ptr<sf::RenderWindow> targetWin) const
{
	if (isVisible && isActive)
		targetWin->draw(text);
}

void TextObject::setOrigin(OriginPos pos)
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

void TextObject::setFont(std::shared_ptr<sf::Font> font)
{
	this->font = font;
	text.setFont(*font);
	size = text.getLocalBounds().getSize();
}

std::wstring TextObject::convertToWString(const std::string& string)
{
	if (string.empty())
		return std::wstring();

	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &string[0], (int)string.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &string[0], (int)string.size(), &wstrTo[0], size_needed);
	return wstrTo;
}