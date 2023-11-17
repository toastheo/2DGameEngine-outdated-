#pragma once
#include "BaseObject.h"
#include <Windows.h>
#include <sstream>

class TextObject : public BaseObject
{
public:
	TextObject(sf::Vector2f position = sf::Vector2f(0, 0), float rotationAngle = 0.0f, sf::Vector2f scale = sf::Vector2f(1, 1), bool isVisible = true, bool isActive = true);

	virtual void update() override;
	const virtual void render(std::shared_ptr<sf::RenderWindow> targetWin) const override;

	virtual void setOrigin(OriginPos pos) override;
	void setFont(std::shared_ptr<sf::Font> font);
	
	template <typename T>
	std::wstring convertToWString(const T& value);
	std::wstring convertToWString(const std::string& string);

	std::wstring string;
	unsigned int characterSizeInPixel;
	sf::Text::Style style;

protected:
	std::shared_ptr<sf::Font> font;
	sf::Text text;
};

template<typename T>
inline std::wstring TextObject::convertToWString(const T& value)
{
	std::wstringstream wss;
	wss << value;
	return wss.str();
}