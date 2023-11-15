#include "GameEngine.h"

int main() 
{
	GameEngine gameEngine;

	while (gameEngine.isRunning())
	{
		gameEngine.update();
	}

	return 0;
}