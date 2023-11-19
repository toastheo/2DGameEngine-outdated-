#include "BlueChicken.h"

void BlueChicken::behaviour()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= speed * elapsedTime;
		if (faceRight)
		{
			flipX();
			faceRight = !faceRight;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += speed * elapsedTime;
		if (!faceRight)
		{
			flipX();
			faceRight = !faceRight;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		position.y -= speed * elapsedTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		position.y += speed * elapsedTime;
	}

	elapsedTime = time.getDeltaTime();
}
