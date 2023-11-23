#include "GameEngine.h"
#include "TestSzene.h"
#include "TestPhyiscs.h"

int main() 
{
	GameEngine gameEngine(true);

	gameEngine.scenePtr = std::make_shared<TestPhyiscs>();

	while (gameEngine.isRunning())
	{
		gameEngine.update();
	}

	return 0;
}
