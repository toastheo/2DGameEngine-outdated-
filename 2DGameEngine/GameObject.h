#pragma once
#include <SFML/Graphics.hpp>
#include "BaseObject.h"

/**
* \class GameObject
* \brief Represents a game object in a 2D game enviroment.
* 
* This class provides the basic properties and behaviors for a game object,
* including position, rotation, scaling, visiblilty and active state.
* It servers as a base class for more specific game objects.
*/
class GameObject : public BaseObject
{
public:
	/**
	* \brief Constructs a GameObject with specified position, rotation, angle, scale, visibility and active state
	* \param position Initial position of the object (default is (0, 0)).
	* \param rotationAngle Initial rotation angle in degrees (default is 0.0f)
	* \param scale Initial scale (default is (1, 1)).
	* \param isVisible Initial visibility state (default is true).
	* \param isActive Initial active state (default is true).
	*/
	GameObject(sf::Vector2f position = sf::Vector2f(0, 0), float rotationAngle = 0.0f, sf::Vector2f scale = sf::Vector2f(1, 1), bool isVisible = true, bool isActive = true);
	
	/**
	* \brief Sets the texture of the GameObject.
	* NOTE: If you change smoothing or repeat, you modify the texture
	* not the gameObject, so it will apply for all objects that are
	* using this Texture.
	* 
	* \param texture Shared pointer to the texture.
	* \param smoothing Apply smoothing to the texture (default is false)
	* \param repeat Repeat the texture (default is false)
	*/
	void setTexture(std::shared_ptr<sf::Texture> texture, bool smoothing = false, bool repeat = false);

	/**
	* \brief Sets the origin position of the GameObject
	* \param textureRect The rectangle area of the texture to use.
	*/
	void setTextureRect(sf::IntRect textureRect);

	/**
	* \brief Sets the origin position of the GameObject.
	* \param pos The origin position to set.
	*/
	virtual void setOrigin(OriginPos pos) override;

	/**
	* \brief Renders the GameObject.
	* \param target The render target.
	*/
	const virtual void render(std::shared_ptr<sf::RenderWindow> targetWin) const override;

	/** \brief Updates the GameObject. */
	virtual void update() override;
protected:
	std::shared_ptr<sf::Texture> texture;	///< Texture of the GameObject.
	sf::Sprite sprite;						///< Sprite used to render the GameObject.
};