#pragma once
#include "Scene.h"
#include "SpriteObject.h"
#include "PhysicWorld.h"

class TestPhyiscs : public Scene
{
	// Geerbt über Scene
	virtual void init() override;
	virtual void update() override;
	virtual void render() const override;

	std::shared_ptr<sf::Texture> ground_tex = std::make_shared<sf::Texture>();
	std::shared_ptr<SpriteObject> ground = std::make_shared<SpriteObject>();
	std::shared_ptr<SpriteObject> ground2 = std::make_shared<SpriteObject>();
	std::shared_ptr<SpriteObject> ground3 = std::make_shared<SpriteObject>();

	std::shared_ptr<sf::Texture> chicken_tex = std::make_shared<sf::Texture>();
	std::shared_ptr<SpriteObject> chicken = std::make_shared<SpriteObject>();

	PhysicWorld pWorld;
};

