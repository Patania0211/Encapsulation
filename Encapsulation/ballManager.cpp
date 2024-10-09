#include "ballManager.h";

int Ball::DrawCircle(SDL_Renderer* renderer) 
{
	int x = Radius;
	int y = 0;

	int centerX = X;
	int centerY = Y;

	int decisionOver2 = 1 - x; // Midpoint circle algorithm decision variable

	while (y <= x) 
	{
		// Draw the eight symmetrical points
		SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
		SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);

		y++;

		// Update decision variable
		if (decisionOver2 <= 0) {
			decisionOver2 += 2 * y + 1; // Midpoint is inside the circle
		}
		else {
			x--;
			decisionOver2 += 2 * y - 2 * x + 1; // Midpoint is outside the circle
		}
	}

	return 0;
}
int Ball::Display(SDL_Renderer* renderer) 
{

	SDL_SetRenderDrawColor(renderer, 255, 178, 78, 255);
	DrawCircle(renderer);

	return 0;
}
int Ball::Movements() 
{

	X += VelocityX;
	Y += VelocityY;

	return 0;
}
int Ball::BorderCollisions() 
{

	if (X >= WINDOW_WIDTH) {
		VelocityX *= -1;
		Y =  Y + VelocityY;
	}
	if (X <= 0) {
		VelocityX *= -1;
		Y = Y + VelocityY;
	}

	if (Y <= 0) {
		VelocityY *= -1;
		X = X + VelocityX;
	}
	if (Y >= WINDOW_HEIGHT) {
		VelocityY *= -1;
		X = X + VelocityX;

	}
	return 0;
}
bool Ball::Collisions(std::vector<Ball>& ballArray) 
{
	int distance;
	bool collision = false;
	//Comparing two balls from the array
	for (int i = 0; i < ballArray.size(); i++) 
	{
		for (int k = i + 1; k < ballArray.size(); k++) 
		{

			distance = sqrt((ballArray[k].X - ballArray[i].X, 2)*(ballArray[k].X - ballArray[i].X, 2)
				+ (ballArray[k].Y - ballArray[i].Y, 2)*(ballArray[k].Y - ballArray[i].Y, 2));

			if (distance <= ballArray[i].Radius + ballArray[k].Radius) 
			{
				collision = true;
				//std::cout << "Collision detected" << std::endl;
			}

			if (collision)
			{
				
				//ballArray[i].X = ballArray[i].X + ballArray[i].VelocityX * -1;
				//ballArray[i].Y = ballArray[i].X + ballArray[i].VelocityY * -1;


				//ballArray[k].X = ballArray[k].X + ballArray[k].VelocityX * -1;
				//ballArray[k].Y = ballArray[k].X + ballArray[k].VelocityY * -1;

			}
		}
	}

	return true;
	

}

void Ball::Update(std::vector<Ball>& ballArray, SDL_Renderer* renderer) {

	Display(renderer);
	Movements();
	BorderCollisions();
	Collisions(ballArray);
	return;
}

void Ball:: Init()
{
	Utilities utility;

	X = utility.randomise(WINDOW_WIDTH);
	Y = utility.randomise(WINDOW_HEIGHT);
	VelocityX = utility.randomise(10);
	VelocityY = utility.randomise(10);

	return;
}