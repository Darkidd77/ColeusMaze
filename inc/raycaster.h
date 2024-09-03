#ifndef RAYCASTER_H
#define RAYCASTER_H

#include <SDL2/SDL.h>

// Raycasting and render walls
void renderWalls(SDL_Renderer* renderer, int map[MAP_HEIGHT][MAP_WIDTH], int screenWidth, int screenHeight, float playerX, float playerY, float playerAngle);

#endif
