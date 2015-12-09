#include "snake.h"

int main()
{
	Game newGame;
	newGame.init();

	while (!GameOver)
	{
		newGame.draw();
		newGame.getInput();
		newGame.logic();
	}



	return 0;
}