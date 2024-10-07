#include "main.h"
#include "ballManager.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


Ball ball1 (10,10,2,2);

using namespace std;
const int temporaryVariable = 11;

int quit = 0;
int x;
int y;

int randomise(int value) {
	int v = rand() % value;
	return v;
}
int main(int argc, char* argv[]) {
	Ball balls[temporaryVariable] = { Ball(x, y,2,2), Ball(x,y,2,2),
	Ball(x,y,2,2), Ball(x,y,2,2), Ball(x,y,2,2), Ball(x,y,2,2),
		Ball(x,y,2,2), Ball(x,y,2,2), Ball(x,y,2,2), Ball(x,y,2,2), Ball(x,y,2,2), };


	for (int i = 0; i < temporaryVariable; i++) {

		balls[i].X = randomise(WINDOW_WIDTH);
		balls[i].Y = randomise(WINDOW_HEIGHT);
		balls[i].VelocityX = randomise(10);
		balls[i].VelocityY = randomise(10);

	}
	
	if (createWindow(&window, &renderer)!= 0) {
		return -1;
	}

	while (!quit) {
		quit = closeWindow(window);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		for (int i = 0; i < temporaryVariable; i++) {

			balls[i].Display(renderer);
			balls[i].Movements();
			balls[i].BorderCollisions();
		}
		//moveBall();
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
