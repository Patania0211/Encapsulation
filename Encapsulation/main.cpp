#include "main.h"
#include "ballManager.h"

using namespace std;

<<<<<<< HEAD
int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	Uint32 startTicks = SDL_GetTicks64();

	Ball ball;
=======
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


Ball ball (0,0,1,1);
int quit = 0;

Uint32 startTicks = SDL_GetTicks64();

std::vector<Ball> balls = {};

int main(int argc, char* argv[]) 
{

	if (createWindow(&window, &renderer)!= 0) {
		return -1;
	}
	while (!quit) {
>>>>>>> 05eb1c21f302232d011e3e80261224e994e47730

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

<<<<<<< HEAD
=======
		Uint32 timeElapsed = SDL_GetTicks64() - startTicks;

		if (timeElapsed >= 1000)
		{
			ball.RandomValuesInit();
			ball.Spawn();
			balls.emplace_back(ball);
			startTicks = SDL_GetTicks64();

		}

		if (balls.size() >= 20)
		{
			balls[0].SetVisibility();
			balls[1].SetVisibility();
			balls.erase(balls.begin());
			balls.shrink_to_fit();
		}

		for (int i = 0; i < balls.size(); i++) {
>>>>>>> 05eb1c21f302232d011e3e80261224e994e47730

		ball.Game(timeElapsed, startTicks, ballArray, ball, renderer);

		SDL_RenderPresent(renderer);
		//SDL_Delay(10);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

void gameManager() 
{

}