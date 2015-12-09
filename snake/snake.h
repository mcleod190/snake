#pragma once

static bool GameOver;
extern enum Direction {STOP=0, UP, DOWN, RIGHT, LEFT};

class Snake
{
	Direction dir;
	unsigned x, y;
public:
	void operator () (int x, int y, Direction d);
	void setDir(Direction d) { this->dir = d; }
	Direction getDir() { return dir; }
	void plusX() { (this->x)++; }
	void plusY() { (this->y)++; }
	void minusY() { (this->y)--; }
	void minusX() { (this->x)--; }
	int getX() { return x; }
	int getY() { return y; }
};



class Food
{
	unsigned x, y;
public:
	void operator () (int x, int y) { this->x = x; this->y = y; }

	int getX() { return x; }
	int getY() { return y; }

};


class Game
{
	Snake s;
	Food f;
	const int width = 20;
	const int height = 20;
public:
	void init();
	void draw();
	void getInput();
	void logic();

};

