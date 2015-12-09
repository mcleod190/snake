#include <ctime>
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "snake.h"


void Game::init()
{
	srand(time(0));
	bool GameOver = false;
	s(width / 2, height / 2, STOP);
	int x, y;
	x = rand() % width;
	y = rand() % height;
	f(x, y);
}


void Game::draw()
{
	using namespace std;
	system("cls");
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
			if (i == 0 || i == (height - 1))
				cout << "#";
			else if (j == 0 || j == (width - 1))
				cout << '#';
			else if ((this->s.getX()) == j && (this->s.getY()) == i)
				cout << 'O';
			else if ((this->f.getX()) == j && (this->f.getY()) == i)
				cout << '$';
			else
				cout << " ";
		cout << endl;		
	}
	Sleep(200);
}

void Game::getInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case 'a': s.setDir(LEFT); break;
			case 'd': s.setDir(RIGHT); break;
			case 'w': s.setDir(UP); break;
			case 's': s.setDir(DOWN); break;
			case 'p': s.setDir(STOP); break;
			case 'x': GameOver = true; break;
		}		
	}
}

void Game::logic()
{
	switch (s.getDir())
	{
	case STOP:
		break;
	case UP:
		s.minusY(); break;
	case DOWN:
		s.plusY(); break;
	case LEFT:
		s.minusX(); break;
	case RIGHT:
		s.plusX(); break;
	default:
		break;
	}
}


void Snake::operator()(int x, int y, Direction d)
{
	this->x = x; this->y = y; this->dir = d;
}
