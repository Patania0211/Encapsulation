#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include <iterator>

#include "constants.h"

class Ball
{
public:
	int X;
	int Y;
	int VelocityX;
	int VelocityY;

	int Radius = 10;

	Ball(int x, int y, int vx, int vy)
	{
		X = x;
		Y = y;
		VelocityX = vx;
		VelocityY = vy;
	};

	int Display(SDL_Renderer* renderer);
	int Movements();
	int BorderCollisions();
	bool Collisions(std::vector<Ball>& ballArray);
	int DrawCircle(SDL_Renderer* renderer);

};