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
	int UpdateMovements();
	int InvertMovements();
	int BorderCollisions();
	void Collisions(std::vector<Ball>& ballArray);

	void CorrectOverlap(std::vector<Ball>& ballArray, double distance, double radiusSum, Ball& ball1, Ball& ball2);

	void Spawn();
	void Remove();
	void Update(std::vector<Ball>& ballArray, SDL_Renderer* renderer);
	~Ball() {};
private:

	int X;
	int Y;
	int VelocityX;
	int VelocityY;
	int R, G, B;

	int Radius = 20;
	bool isVisible = true;
};