//#include "GameEngine.h"
//#include "TestSzene.h"
//#include "box2d/box2d.h"
//
//int main() 
//{
//	GameEngine gameEngine;
//
//	gameEngine.scenePtr = std::make_shared<TestSzene>();
//
//	while (gameEngine.isRunning())
//	{
//		gameEngine.update();
//	}
//
//	return 0;
//}

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "GameTime.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D und SFML");
    window.setFramerateLimit(60);

    // Box2D-Welt initialisieren
    b2Vec2 gravity(0.0f, 100.f);
    b2World world(gravity);

    // Einen statischen Boden erstellen
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(400.0f, 400.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Einen dynamischen Körper erstellen
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(455.0f, 100.0f);
    b2Body* body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 10.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    // SFML-Form für den dynamischen Körper
    sf::RectangleShape box(sf::Vector2f(20.0f, 20.0f));
    box.setFillColor(sf::Color::Green);
    box.setOrigin(10.0f, 10.0f);

    // SFML-Form für den statischen Boden
    sf::RectangleShape ground(sf::Vector2f(100.f, 20.f));
    ground.setFillColor(sf::Color::Red);
    ground.setOrigin(50.f, 10.f);

    b2Vec2 groundPosition = groundBody->GetPosition();
    float groundAngle = groundBody->GetAngle();
    ground.setPosition(groundPosition.x, groundPosition.y);
    ground.setRotation(groundAngle * 180.f / b2_pi);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        world.Step(1 / 60.f, 8, 3);

        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        box.setPosition(position.x, position.y);
        box.setRotation(angle * 180.0f / b2_pi);

        window.clear();
        window.draw(box);
        window.draw(ground);
        window.display();
    }

    return 0;
}
