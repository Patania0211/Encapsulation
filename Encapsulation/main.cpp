#include "main.h"

using namespace std;

int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	Uint32 startTicks = SDL_GetTicks64();

	Ball ball;

	int quit = 0;


	std::vector<Ball> ballArray = {};
	
	if (SDLInit(&window, &renderer) !=0) {return -1;}

	std::srand(static_cast<unsigned int>(std::time(0)));

	while (!quit) 
	{
		quit = SDLCleanUp(window);

		Uint32 timeElapsed = SDL_GetTicks64() - startTicks;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);


		if (timeElapsed >= 1000)
		{
			ball.Init(ballArray, ball);
			startTicks = SDL_GetTicks64();

		}
		if (ballArray.size() >= MAX_BALL_AMOUNT)
		{
			ball.Delete(ballArray);
		}

		for (int i = 0; i < ballArray.size(); i++)
		{
			ballArray[i].Update(ballArray, renderer);
		}
		//ball.Game(timeElapsed, startTicks, ballArray, ball, renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}