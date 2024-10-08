#include "ballManager.h";

int Ball::DrawCircle(SDL_Renderer* renderer) {
	int x = Radius;
	int y = 0;

	int centerX = X;
	int centerY = Y;

	int decisionOver2 = 1 - x; // Midpoint circle algorithm decision variable

	while (y <= x) {
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
int Ball::Display(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer, 255, 182, 193, 255);
	DrawCircle(renderer);

	return 0;
}
int Ball::Movements() {

	X += VelocityX;
	Y += VelocityY;

	return 0;
}
int Ball::BorderCollisions() {

	if (X >= WINDOW_WIDTH /*- Radius*/) {
		// Il faut modifier la composante 
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
	if (Y >= WINDOW_HEIGHT /*- Radius*/) {
		VelocityY *= -1;
		X = X + VelocityX;

	}
	return 0;
}
bool Ball::Collisions(std::vector<Ball> ballArray, int arrayLength) {
	for (int i = 0; i < arrayLength; i++) 
	{
		for (int k = i + 1; k < arrayLength; k++) 
		{
			if (ballArray[i].X == ballArray[k].X && ballArray[i].Y == ballArray[k].Y)
			{
				std::cout << "Collisons detected \n";
				return true;
			}

		}

	}

	//for (int i = 0; i < arrayLength; i++) {
	//	Ball previousBall = ballArray[i+1];

	//	if (ballArray[i].X == previousBall.X) {

	//		std::cout << "Colision detected";
	//		return true;
	//	}
	//}
}