#ifndef RAYCASTER_H
#define RAYCASTER_H

#include <SDL2/SDL.h>

// Define Pi for angle calculations
#define PI 3.14159265359

// Variables for player position and angle
extern float playerX;
extern float playerY;
extern float playerAngle;

// Cast a ray and render a wall slice
void castRay(SDL_Renderer* renderer, int x);

// Render the entire scene using raycasting
void renderScene(SDL_Renderer* renderer);

#endif
