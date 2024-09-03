#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>

// Init SDL2 and creates a window
bool initSDL(SDL_Window*& window, SDL_Renderer*& renderer, const char* title, int width, int height);

// Cleans up and shuts down
void closeSDL(SDL_Window* window, SDL_Renderer* renderer);

#endif
