#pragma once
#include <SFML/Graphics.hpp>
#include "GameTime.h"

class BaseObject
{
public:
	BaseObject(sf::Vector2f position, float rotationAngle, sf::Vector2f scale, bool isVisible, bool isActive);
	~BaseObject() {};

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
	* \brief Retrieves the size of the GameObject.
	* \return The size of the GameObject as an sf::Vector2f.
	*/
	sf::Vector2f getSize();

	virtual void update() = 0;
	const virtual void render(std::shared_ptr<sf::RenderWindow> targetWin) const = 0;

	virtual void setOrigin(OriginPos pos) = 0;

	// Member variables
	sf::Vector2f position;					///< Position of the Object.
	float rotationAngle;					///< Rotation angle of the Object.
	sf::Vector2f scale;						///< Scale of the Object.
	sf::Color color;						///< Color of the Object.
	sf::Vector2f motionVector;				///< Motion vector for the movement.
	float rotationVector;					///< Rotation vector for the rotation.
	sf::Vector2f scalingVector;				///< Scaling vector for scaling.
	sf::Vector2f origin;					///< Origin point of the Object.

	bool isVisible;							///< Visibility state of the Object.
	bool isActive;							///< Active state of the Object.

protected:
	sf::Vector2f size;						///< Size of the Object.

	GameTime time;							///< Tracks time to calculate DeltaTime.
	bool loopStarted = false;				///< Tracks if the Object loop has started.

	/**
	* \brief Method for additional initializations in derived classes.
	*/
	virtual void start() {};

	/**
	* \brief Defines the behaviour of the GameObject.
	*/
	virtual void behaviour() {};
};

