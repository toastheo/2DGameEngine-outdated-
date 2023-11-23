#pragma once
#include "BaseObject.h"

/**
* \class CircleShapeObject
* \brief Represents a circular shape object in a 2D game enviroment.
* 
* This class is a specialized form of BaseObject that provides functionality
* for displaying and manipulating circle-based shapes within a game. It supports
* various geometrical shapes like circles, triangles, squares and octagons.
* Properties such as position, rotation, scale, visibility and active state
* are inherited from BaseObject.
*/
class CircleShapeObject : public BaseObject
{
public:

	/**
	* \brief Constructs a CircleShapeObject with specified position, rotation, angle, scale, visibility and active state
	* \param position Initial position of the object (default is (0, 0)).
	* \param rotationAngle Initial rotation angle in degrees (default is 0.0f)
	* \param scale Initial scale (default is (1, 1)).
	* \param isVisible Initial visibility state (default is true).
	* \param isActive Initial active state (default is true).
	*/
	CircleShapeObject(sf::Vector2f position = sf::Vector2f(0, 0), float rotationAngle = 0.0f, sf::Vector2f scale = sf::Vector2f(1, 1), bool isVisible = true, bool isActive = true);

	/**
	* \brief Enum to represent different shape types.
	*/
	enum class Shapes
	{
		Circle,
		Triangle,
		Square,
		Octagon
	};

	/**
	* \brief Updates the CircleShapeObject.
	*/
	virtual void update() override;

	/**
	* \brief Renders the CircleShapeObject.
	* \param targetWin Shared pointer to render target window.
	*/
	virtual void render(std::shared_ptr<sf::RenderWindow> targetWin) const override;

	/**
	* \brief Sets the texture of the CircleShapeObject.
	* NOTE: If you change smoothing or repeat, you modify the texture
	* not the CircleShape, so it will apply for all objects that are
	* using this Texture.
	*
	* \param texture Shared pointer to the texture.
	* \param smoothing Apply smoothing to the texture (default is false)
	* \param repeat Repeat the texture (default is false)
	*/
	void setTexture(std::shared_ptr<sf::Texture> texture, bool smoothing = false, bool repeat = false);

	/**
	* \brief Sets the origin position of the CircleShapeObject
	* \param textureRect The rectangle area of the texture to use.
	*/
	void setTextureRect(sf::IntRect textureRect);

	/**
	* \brief Defines the shape based on radius and predefined shape type.
	* \param radius Radius of the shape.
	* \param numberOfPoints Number of the points defining the shape.
	*/
	void defineShape(float radius, unsigned int numberOfPoints);

	/**
	* \brief Defines the shape based on radius and predefined shape type.
	* \param radius Radius of the shape.
	* \param shape Predefined shape type (Circle, Triangle, Square, Octagon).
	*/
	void defineShape(float radius, Shapes shape);

	float outlineThickness;							///< Thickness of the outline of the shape.
	sf::Color outlineColor;							///< Color of the outline of the shape.

protected:
	sf::CircleShape shape;							///< sf::CircleShape object used to render the shape.
	std::shared_ptr<sf::Texture> texture;			///< Texture of the CircleShapeObject.
};

