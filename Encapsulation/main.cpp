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

int main(int argc, char* argv[]) {
	std::vector<Ball> balls = { Ball(x, y,2,2), Ball(x,y,2,2),Ball(x,y,2,2),Ball(x,y,2,2), Ball(x,y,2,2), Ball(x,y,2,2),
	Ball(x, y, 2, 2), Ball(x, y, 2, 2), Ball(x, y, 2, 2), Ball(x, y, 2, 2), Ball(x, y, 2, 2)};

	for (int i = 0; i < balls.size(); i++) {
		balls[i].Init();
	}
	if (createWindow(&window, &renderer)!= 0) {
		return -1;
	}
	while (!quit) {

		quit = closeWindow(window);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		for (int i = 0; i < balls.size(); i++) {
			balls[i].Update(balls, renderer);
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
