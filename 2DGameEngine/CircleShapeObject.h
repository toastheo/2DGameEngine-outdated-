#pragma once
#include "BaseObject.h"

class CircleShapeObject : public BaseObject
{
public:
	CircleShapeObject(sf::Vector2f position = sf::Vector2f(0, 0), float rotationAngle = 0.0f, sf::Vector2f scale = sf::Vector2f(1, 1), bool isVisible = true, bool isActive = true);

	enum class Shapes
	{
		Circle,
		Triangle,
		Square,
		Octagon
	};

	virtual void update() override;
	const virtual void render(std::shared_ptr<sf::RenderWindow> targetWin) const override;

	void setTexture(std::shared_ptr<sf::Texture> texture, bool smoothing = false, bool repeat = false);
	void setTextureRect(sf::IntRect textureRect);

	virtual void setOrigin(OriginPos pos) override;

	void defineShape(float radius, unsigned int numberOfPoints);
	void defineShape(float radius, Shapes shape);

	float outlineThickness;
	sf::Color outlineColor;

protected:
	sf::CircleShape shape;
	std::shared_ptr<sf::Texture> texture;
};

