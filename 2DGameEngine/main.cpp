#include "GameEngine.h"
#include "TestSzene.h"

int main() 
{
	GameEngine gameEngine;

	gameEngine.scenePtr = std::make_shared<TestSzene>();

	while (gameEngine.isRunning())
	{
		gameEngine.update();
	}

	return 0;
}