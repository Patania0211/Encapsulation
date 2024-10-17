#pragma once
#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "constants.h"

int SDLInit(SDL_Window** window, SDL_Renderer** renderer);
int SDLCleanUp(SDL_Window* window);

