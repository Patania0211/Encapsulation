#include "ballManager.h";

void Ball:: RandomValuesInit()
{
	Utilities utility;

	X = utility.randomise(WINDOW_WIDTH);
	Y = utility.randomise(WINDOW_HEIGHT);
	VelocityX = utility.randomise(10);
	VelocityY = utility.randomise(10);

	R = utility.randomise(255);
	G = utility.randomise(255);
	B = utility.randomise(255);

	Radius = utility.randomise(25);

	return;
}


int Ball::DrawCircle(SDL_Renderer* renderer)
{
	//I'm sorry <3 
	// 
	// That was the v1 of my circles
	// 
	// 
	//int x = Radius;
	//int y = 0;

	//int centerX = X;
	//int centerY = Y;

	//int decisionOver2 = 1 - x; // Midpoint circle algorithm decision variable

	//while (y <= x) 
	//{
	//	// Draw the eight symmetrical points
	//	SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
	//	SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
	//	SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
	//	SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
	//	SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
	//	SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
	//	SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
	//	SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);

	//	y++;

	//	// Update decision variable
	//	if (decisionOver2 <= 0) {
	//		decisionOver2 += 2 * y + 1; // Midpoint is inside the circle
	//	}
	//	else {
	//		x--;
	//		decisionOver2 += 2 * y - 2 * x + 1; // Midpoint is outside the circle
	//	}
	//}

	for (int w = 0; w < Radius * 2; w++)
	{
		for (int h = 0; h < Radius * 2; h++)
		{

			int dx = Radius - w; // horizontal offset
			int dy = Radius - h; // vertical offset

			if ((dx * dx + dy * dy) <= (Radius * Radius))
			{
				SDL_RenderDrawPoint(renderer, X + dx, Y + dy);
			}
		}
	}
	return 0;
}
int Ball::Display(SDL_Renderer* renderer) 
{
	if (!isVisible) { return 0; }

	SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	DrawCircle(renderer);

	return 0;
}
int Ball::UpdateMovements() 
{

	X += VelocityX;
	Y += VelocityY;

	return 0;
}
int Ball::InvertMovements() 
{
	VelocityX *= -1;
	VelocityY *= -1;

	UpdateMovements();

	return 0;
}
int Ball::BorderCollisions()
{
	if (X >= WINDOW_WIDTH) {

		X = WINDOW_WIDTH;
		VelocityX *= -1;

	}
	else if (X <= 0) 
	{
		X = 0;
		VelocityX *= -1;
	}

	if (Y >= WINDOW_HEIGHT) {

		Y = WINDOW_HEIGHT;
		VelocityY *= -1;
	}
	else if (Y <= 0) 
	{
		Y = 0;
		VelocityY *= -1;
	}

	UpdateMovements();

	return 0;
}
void Ball::Collisions(std::vector<Ball>& ballArray)
{
	//Comparing two balls from the array
	for (int i = 0; i < ballArray.size(); i++)
	{
		for (int k = i + 1; k < ballArray.size(); k++)
		{
			double distance = sqrt(pow(ballArray[k].X - ballArray[i].X, 2) + pow(ballArray[k].Y - ballArray[i].Y, 2));
			int radiusSum = ballArray[i].Radius + ballArray[k].Radius;

			if (distance <= radiusSum)
			{
				ballArray[i].InvertMovements();
				ballArray[k].InvertMovements();

			}
			if (distance < radiusSum)
			{
				CorrectOverlap(ballArray, distance, radiusSum, ballArray[i], ballArray[k]);
			}
		}


	}
		return;
}
//WORK IN PROGRESS
void Ball::CorrectOverlap(std::vector<Ball>& ballArray, double distance, double radiusSum, Ball& ball1, Ball& ball2)
{
	double overlap = radiusSum - distance;

	double dx = ball2.X - ball1.X;
	double dy = ball2.Y - ball1.Y;

	double distanceFactor = distance == 0 ? 1 : (1.0 / distance);
	dx *= distanceFactor;
	dy *= distanceFactor;

	ball1.X -= dx * (overlap / 2);
	ball1.Y -= dy * (overlap / 2);

	ball2.X += dx * (overlap / 2);
	ball2.Y += dy * (overlap / 2);
}
void Ball::Spawn()
{
	Ball{ X,Y,VelocityX, VelocityY };

	return;

}
void Ball::SetVisibility()
{
	isVisible = false;
	return;
}

void Ball::Update(std::vector<Ball>& ballArray, SDL_Renderer* renderer) 
{
	Display(renderer);
	BorderCollisions();
	Collisions(ballArray);
	//UpdateMovements();
	return;
}


