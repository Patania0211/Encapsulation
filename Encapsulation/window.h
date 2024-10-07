#pragma once
#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "constants.h"

int createWindow(SDL_Window** window, SDL_Renderer** renderer);
int closeWindow(SDL_Window* window);

