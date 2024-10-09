#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>


#include "constants.h"
#include "utilities.h"

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

	void Init();
	int DrawCircle(SDL_Renderer* renderer);
	int Display(SDL_Renderer* renderer);
	int Movements();
	int BorderCollisions();
	void Collisions(std::vector<Ball>& ballArray);
	//bool Collisions(Ball ball1, Ball ball2);

	void CorrectOverlap(std::vector<Ball>& ballArray,
		double distance, double radiusSum);

	void Update(std::vector<Ball>& ballArray, SDL_Renderer* renderer);
	

private:

	int R;
	int G;
	int B;

};