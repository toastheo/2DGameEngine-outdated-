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
	lastPos = position;

	text.setRotation(rotationAngle);
	text.setScale(scale);
	size = text.getGlobalBounds().getSize();
	text.setFillColor(color);
	
	size = text.getLocalBounds().getSize();
	globalBounds = text.getGlobalBounds();

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

void TextObject::render(std::shared_ptr<sf::RenderWindow> targetWin) const
{
	if (isVisible && isActive)
		targetWin->draw(text);
}

void TextObject::setFont(std::shared_ptr<sf::Font> font)
{
	this->font = font;
	text.setFont(*font);
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