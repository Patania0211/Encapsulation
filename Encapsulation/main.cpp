#include "main.h"
#include "ballManager.h"

using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


Ball ball (0,0,1,1);


int quit = 0;
int x;
int y;

int main(int argc, char* argv[]) {
	Uint32 startTicks = SDL_GetTicks64();
	std::vector<Ball> balls = {};
	if (createWindow(&window, &renderer)!= 0) {
		return -1;
	}
	while (!quit) {

		quit = closeWindow(window);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		Uint32 timeElapsed = SDL_GetTicks64() - startTicks;

		if (timeElapsed >= 1000)
		{
			ball.Init();
			ball.Spawn();
			balls.emplace_back(ball);
			startTicks = SDL_GetTicks64();
			//std::cout << ballCount << endl;
			std::cout << balls.size()<< endl;

		}

		if (balls.size() >= 30)
		{
			balls[0].Remove();
			balls.erase(balls.begin());
			balls.shrink_to_fit();
		}


		
		for (int i = 0; i < balls.size(); i++) {

			balls[i].Update(balls, renderer);
		}

		SDL_RenderPresent(renderer);
		//SDL_Delay(10);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
