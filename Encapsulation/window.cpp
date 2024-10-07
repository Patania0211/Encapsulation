#include "window.h"
int createWindow(SDL_Window** window, SDL_Renderer** renderer) {

	//Initialization
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error window initialization failed\n");
		return -1;
	}
	//Creating a window with SDL
	*window = SDL_CreateWindow("Encapsulation", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	//Checking for error
	if (*window == NULL) {
		printf("Error when creating the window\n");
		SDL_Quit();
		return -1;
	}
	//Creating the renderer system
	*renderer = SDL_CreateRenderer(*window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Checking for error
	if (*renderer == NULL) {
		printf("Error when processing the renderer\n");
		SDL_Quit();
		return -1;
	}
	return 0;
}
int closeWindow(SDL_Window* window) {

	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			return 1;
		}
	}
	return 0;
}