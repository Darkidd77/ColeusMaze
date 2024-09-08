#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include "game.h"  // Include this to use MAP_WIDTH and MAP_HEIGHT

// Draw walls (N/S or E/W)
void drawWalls(SDL_Renderer* renderer, int x, int drawStart, int drawEnd, int side);

// Render all walls based on the map and player position
void renderWalls(SDL_Renderer* renderer, int map[MAP_HEIGHT][MAP_WIDTH], int screenWidth, int screenHeight, float playerX, float playerY, float playerAngle);

#endif
