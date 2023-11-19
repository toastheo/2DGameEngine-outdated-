#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameTime.h"

/**
* \class Scene
* \brief Represents a scene in a 2D game enviroment.
* 
* This class is designed to be a base for different scenes in a game, such as menus, levels, or cutscenes.
* It provides basic functionalities for initializing, updating and rendering a scene. The class
* als handles the core aspects of a scene, such as managing its own render window and tracking wheter
* the scene loop has started.
*/
class Scene
{
public:

	/**
	* \brief Constructor of the Scene class.
	*/
	Scene();

	/**
	* \brief Destructor of the Scene class.
	*/
	~Scene();

	/**
	* \brief Loads the scene into the specified render window.
	* \param targetWin Shared pointer to the render window where the scene will be displayed.
	*/
	void load(std::shared_ptr<sf::RenderWindow> targetWin);

protected:

	/**
	* \brief Initializes the scene. Must be implemented by derived classes.
	*/
	virtual void init() = 0;

	/**
	* \brief Updates the scene. Must be implemented by derived classes.
	* this function is intended to contain the logic for updating the state of the scenem
	* such as handling user input or updating the game objects.
	*/
	virtual void update() = 0;

	/**
	* \brief Renders the scene. Must be implemented by derived classes.
	* This function is intended to contain all the drawing calls necessary to render the scene.
	*/
	virtual void render() const = 0;

	std::shared_ptr<sf::RenderWindow> targetWin;		///< Shared pointer to the render window.
	bool startedSceneLoop = false;						///< Indicates wheter the scene loop has been started.
};

