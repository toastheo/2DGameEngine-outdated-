#include "GameEngine.h"
#include "TestSzene.h"
#include "box2d/box2d.h"

int main() 
{
	GameEngine gameEngine(true);

	gameEngine.scenePtr = std::make_shared<TestSzene>();

	while (gameEngine.isRunning())
	{
		gameEngine.update();
	}

	return 0;
}
