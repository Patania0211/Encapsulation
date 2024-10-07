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


	//SDL_Rect ballRect{ ball1.ballPosX += ball1.ballVelocity, ball1.ballPosY += ball1.ballVelocity, BALLSIZE,BALLSIZE };
	
	//SDL_Rect ballRect{ X, Y, BALLSIZE,BALLSIZE };
	SDL_SetRenderDrawColor(renderer, 255, 182, 193, 255);
	DrawCircle(renderer);
	//SDL_RenderPresent(renderer);

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
int Ball::Collisions(std::vector<Ball> ballArray) {
	
	auto arrayLength = std::distance(ballArray.begin(), ballArray.end());
	/*for (int firstBall = 0; firstBall < arrayLength; firstBall++) {
		for (int secondBall = 0; secondBall < arrayLength; secondBall++) {

			std::cout<< "I'm miss potato";
		}

	}*/
	
	return 0;
}