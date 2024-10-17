#include "main.h"
#include "ballManager.h"

using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


Ball ball(0, 0, 1, 1);
int quit = 0;

Uint32 startTicks = SDL_GetTicks64();

std::vector<Ball> ballArray = {};

int main(int argc, char* argv[])
{
	if (createWindow(&window, &renderer) !=0) {return -1;}
	while (!quit) 
	{

		std::srand(std::time(0));
		quit = closeWindow(window);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		Uint32 timeElapsed = SDL_GetTicks64() - startTicks;

		if (timeElapsed >= 1000)
		{
			ball.Init(ballArray, ball);
			startTicks = SDL_GetTicks64();

		}
		if (ballArray.size() >= MAX_BALL_AMOUNT){ball.Delete(ballArray);}
		for (int i = 0; i < ballArray.size(); i++) {ballArray[i].Update(ballArray, renderer);}

		SDL_RenderPresent(renderer);
		//SDL_Delay(10);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}