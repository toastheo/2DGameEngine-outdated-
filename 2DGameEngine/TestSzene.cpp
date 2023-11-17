#include "TestSzene.h"

void TestSzene::init()
{
	// test gameObject
	blue_chicken_texture = std::make_shared<sf::Texture>();

	if (!blue_chicken_texture->loadFromFile("BlueChickenIdle-Sheet.png"))
	{
		std::cout << "Error trying to load Blue Chicken Texture." << std::endl;
	}

	blue_chicken.setTexture(blue_chicken_texture);
	blue_chicken.scale = sf::Vector2f(10.f, 10.f);
	blue_chicken.setTextureRect(sf::IntRect(0, 0, blue_chicken.getSize().x / 5.f, blue_chicken.getSize().y));
	blue_chicken.motionVector = sf::Vector2f(50.f, 0);
	blue_chicken.position.y += 50.f;

	// test textobject
	TimeDisplay_font = std::make_shared<sf::Font>();

	if (!TimeDisplay_font->loadFromFile("Arimo-VariableFont_wght.ttf"))
	{
		std::cout << "Error trying to load Arimo-VariableFont_wght." << std::endl;
	}

	TimeDisplay.setFont(TimeDisplay_font);
	TimeDisplay.color = sf::Color::Red;
	TimeDisplay.characterSizeInPixel = 24;

	// test circleshapeobject
	wood_texture = std::make_shared<sf::Texture>();

	if (!wood_texture->loadFromFile("woodTexture.jpg"))
	{
		std::cout << "Error trying to load Wood Texture." << std::endl;
	}

	circle.defineShape(80.f, CircleShapeObject::Shapes::Circle);
	circle.position = sf::Vector2f(0, 500.f);
	circle.setTexture(wood_texture);
	
	triangle.defineShape(80.f, CircleShapeObject::Shapes::Triangle);
	triangle.color = sf::Color::Blue;
	triangle.position = circle.position;
	triangle.position.x += 200.f;

	square.defineShape(80.f, CircleShapeObject::Shapes::Square);
	square.color = sf::Color::Magenta;
	square.position = circle.position;
	square.position.x += 400.f;

	octagon.defineShape(80.f, CircleShapeObject::Shapes::Octagon);
	octagon.color = sf::Color::Red;
	octagon.position = circle.position;
	octagon.position.x += 600.f;

	sides12.defineShape(80.f, 12);
	sides12.color = sf::Color::Yellow;
	sides12.position = circle.position;
	sides12.position.x += 800.f;
	sides12.outlineThickness = 5.f;
	sides12.outlineColor = sf::Color::White;
}

void TestSzene::update()
{
	TimeDisplay.string = L"Time elapsed: " + TimeDisplay.convertToWString(timer.getTotalLiveTime().asSeconds());

	blue_chicken.update();
	TimeDisplay.update();

	circle.update();
	triangle.update();
	square.update();
	octagon.update();
	sides12.update();
}

void TestSzene::render()
{
	blue_chicken.render(targetWin);
	TimeDisplay.render(targetWin);
	circle.render(targetWin);
	triangle.render(targetWin);
	square.render(targetWin);
	octagon.render(targetWin);
	sides12.render(targetWin);
}
