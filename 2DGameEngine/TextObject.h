#pragma once
#include "BaseObject.h"
#include <Windows.h>
#include <sstream>

/**
* \class TextObject
* \brief Represents a text object in a 2D game enviroment.
* 
* This class provides functionality to display and manipulate text within a game.
* It inherits from BaseObject, providing basic properties like position, rotation,
* scale, visbility and active state. Additional features include setting font, size,
* style and the actual text content.
*/
class TextObject : public BaseObject
{
public:
	/**
	* \brief Constructs a TextObject with specified position, rotation, angle, scale, visibility and active state
	* \param position Initial position of the object (default is (0, 0)).
	* \param rotationAngle Initial rotation angle in degrees (default is 0.0f)
	* \param scale Initial scale (default is (1, 1)).
	* \param isVisible Initial visibility state (default is true).
	* \param isActive Initial active state (default is true).
	*/
	TextObject(sf::Vector2f position = sf::Vector2f(0, 0), float rotationAngle = 0.0f, sf::Vector2f scale = sf::Vector2f(1, 1), bool isVisible = true, bool isActive = true);

	/** \brief Updates the SpriteObject. */
	virtual void update() override;

	/**
	* \brief Renders the SpriteObject.
	* \param targetWin Shared pointer to render target window.
	*/
	virtual void render(std::shared_ptr<sf::RenderWindow> targetWin) const override;

	/**
	* \brief Sets the font for the text.
	* \param font Shared pointer to the sf::Font object.
	*/
	void setFont(std::shared_ptr<sf::Font> font);
	
	/**
	* \brief Converts a value of any type to a wide string.
	* \param value The value to convert.
	* \return The converted wide string.
	*/
	template <typename T>
	std::wstring convertToWString(const T& value);

	/**
	* \brief Converts a standart string to a wide string.
	* \param string The standart string to convert.
	* \return The converted wide string.
	*/
	std::wstring convertToWString(const std::string& string);

	std::wstring string;						///< The text content.
	unsigned int characterSizeInPixel;			///< Size of the character in pixels.
	sf::Text::Style style;						///< Style of the text (bold, italic, etc.)

protected:
	std::shared_ptr<sf::Font> font;				///< Font used for the text.
	sf::Text text;								///< sf::Text object used to render the text.
};

template<typename T>
inline std::wstring TextObject::convertToWString(const T& value)
{
	std::wstringstream wss;
	wss << value;
	return wss.str();
}