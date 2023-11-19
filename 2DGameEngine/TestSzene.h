#pragma once
#include "Scene.h"
#include "BlueChicken.h"
#include "TextObject.h"
#include "GameTime.h"
#include "CircleShapeObject.h"

class TestSzene : public Scene
{
	// Geerbt über Scene
	virtual void init() override;
	virtual void update() override;
	virtual void render() const override;

	// test gameobject
	std::shared_ptr<sf::Texture> blue_chicken_texture;
	BlueChicken blue_chicken;

	// test textobject
	std::shared_ptr<sf::Font> TimeDisplay_font;
	TextObject TimeDisplay;
	GameTime timer;

	// test circleshapeobject
	std::shared_ptr<sf::Texture> wood_texture;

	CircleShapeObject circle;
	CircleShapeObject triangle;
	CircleShapeObject square;
	CircleShapeObject octagon;
	CircleShapeObject sides12;
};