#pragma once
#include <SFML/Graphics.hpp>

/**
* \class GameTime
* \brief Manages and tracks time within a game enviroment.
* 
* This class is responsible for tracking the total time since the game started and
* the time between frames (delta time). It is essential for time-dependent calculations
* like animations, movements and game logic that need to be updated regularly.
*/
class GameTime
{
public:
	/**
	* \brief Constructor of the GameTime class.
	* Initializes the internal clock and time tracking variables.
	*/
	GameTime();

	/**
	* \brief Destructor of the GameTime class.
	*/
	~GameTime() {};

	/**
	* \brief Retrieves the time elapsed since the game started.
	* \return A sf::Time object representing the total elapsed time.
	*/
	sf::Time getTotalLiveTime() const;

	/**
	* \brief Retrieves the time elapsed since the last frame.
	* \return A float representing the delta time in seconds.
	*/
	float getDeltaTime();

	/*
	* \brief Resets the internal clock.
	* \return a sf::Time object representing the total elapsed time.
	*/
	sf::Time reset();

private:
	sf::Clock clock;				///< Internal clock to track the total live time.
	sf::Time lastFrameTime;			///< Time at the last frame, used to calculate delta time.
	sf::Time deltaTime;				///< Time elapsed since the last frame.
};

