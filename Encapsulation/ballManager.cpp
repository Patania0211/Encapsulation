#include "ballManager.h";




int Ball::Display(SDL_Renderer* renderer) {


	//SDL_Rect ballRect{ ball1.ballPosX += ball1.ballVelocity, ball1.ballPosY += ball1.ballVelocity, BALLSIZE,BALLSIZE };
	
	SDL_Rect ballRect{ X, Y, BALLSIZE,BALLSIZE };
	SDL_SetRenderDrawColor(renderer, 255, 182, 193, 255);
	SDL_RenderFillRect(renderer, &ballRect);
	//SDL_RenderPresent(renderer);

	return 0;
}
int Ball::Movements() {

	X += VelocityX;
	Y += VelocityY;

	return 0;
}
int Ball::BorderCollisions() {

	if (X >= WINDOW_WIDTH - BALLSIZE) {
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
	if (Y >= WINDOW_HEIGHT - BALLSIZE) {
		VelocityY *= -1;
		X = X + VelocityX;

	}
	return 0;
}
int Ball::Collisions() {
	SDL_bool SDL_HasIntersection();
	return 0;
}