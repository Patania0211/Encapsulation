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
	void Init(std::vector<Ball>& ballArray, Ball ball);

	void RandomValuesInit();
	void Spawn();
	void SetVisibility();
	void Update(std::vector<Ball>& ballArray, SDL_Renderer* renderer);
	void Delete(std::vector<Ball>& ballArray);
	~Ball() {
		X, Y, VelocityX, VelocityY, R,G,B = 0;
	};

private:

	int X;
	int Y;
	int VelocityX;
	int VelocityY;
	int R, G, B;
	int Radius = 20;

	bool isVisible = true;


	int invertMovements();
	void collisions(std::vector<Ball>& ballArray);
	void correctOverlap(std::vector<Ball>& ballArray, double distance, double radiusSum, Ball& ball1, Ball& ball2);
	int display(SDL_Renderer* renderer);
	int updateMovements();
	int drawCircle(SDL_Renderer* renderer);
	int borderCollisions();





};