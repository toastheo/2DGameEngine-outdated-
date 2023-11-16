#pragma once
#include <SFML/Graphics.hpp>
#include "GameTime.h"

/**
* \class GameObject
* \brief Represents a game object in a 2D game enviroment.
* 
* This class provides the basic properties and behaviors for a game object,
* including position, rotation, scaling, visiblilty and active state.
* It servers as a base class for more specific game objects.
*/
class GameObject
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

	/** \brief Destructor for GameObject. */
	~GameObject();

	/**
	* \enum OriginPos
	* \brief Represents the origin position for the GameObject.
	*/
	enum class OriginPos
	{
		UpLeft,			///< Origin at the upper left corner.
		UpRight,		///< Origin at the upper right corner.
		DownLeft,		///< Origin at the lower right corner.
		DownRight,		///< Origin at the lower right corner.
		Center			///< Origin at the center.
	};
	
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
	void setOrigin(OriginPos pos);

	/**
	* \brief Retrieves the size of the GameObject.
	* \return The size of the GameObject as an sf::Vector2f.
	*/
	sf::Vector2f getSize();

	/**
	* \brief Renders the GameObject.
	* \param target The render target.
	*/
	void render(std::shared_ptr<sf::RenderWindow> targetWin);

	/** \brief Updates the GameObject. */
	void update();
	
	/**
	* \brief Method for additional initializations in derived classes.
	*/
	virtual void start() {};

	/**
	* \brief Defines the behaviour of the GameObject.
	*/
	virtual void behaviour() {};

	// Member variables
	sf::Vector2f position;					///< Position of the GameObject.
	float rotationAngle;					///< Rotation angle of the GameObject.
	sf::Vector2f scale;						///< Scale of the GameObject.
	sf::Color color;						///< Color of the GameObject.
	sf::Vector2f motionVector;				///< Motion vector for the movement.
	float rotationVector;					///< Rotation vector for the rotation.
	sf::Vector2f scalingVector;				///< Scaling vector for scaling.
	sf::Vector2f origin;					///< Origin point of the GameObject.

	bool isVisible;							///< Visibility state of the GameObject.
	bool isActive;							///< Active state of the GameObject.

private:
	sf::Vector2f size;						///< Size of the GameObject.
	std::shared_ptr<sf::Texture> texture;	///< Texture of the GameObject.
	sf::Sprite sprite;						///< Sprite used to render the GameObject.

	GameTime time;							///< Tracks time to calculate DeltaTime.
	bool loopStarted = false;				///< Tracks if the GameObject loop has started.
};