#include "raycaster.h"
#include <cmath>
#include <SDL2/SDL.h>

// Constants
const int mapWidth = 10;
const int mapHeight = 10;
const int screenWidth = 1280;
const int screenHeight = 720;
const float FOV = 60.0f * (PI / 180.0f); // 60 degrees in radians

// Map (1 = wall, 0 = empty space)
int worldMap[mapHeight][mapWidth] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// The Player position and orientation
float playerX = 2.0f;
float playerY = 2.0f;
float playerAngle = PI / 2;  // Facing EAST initially

// Cast a single ray and determine wall height
void castRay(SDL_Renderer* renderer, int x) {
    float cameraX = 2 * x / float(screenWidth) - 1; // Screen X-coordinate mapped to -1 to 1
    float rayDirX = cos(playerAngle) + cameraX * cos(playerAngle + FOV / 2);
    float rayDirY = sin(playerAngle) + cameraX * sin(playerAngle + FOV / 2);

    int mapX = int(playerX);
    int mapY = int(playerY);

    // Distance to the next x or y side in the grid
    float sideDistX, sideDistY;

    // Length of ray from one side to next in x or y
    float deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
    float deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

    float perpWallDist;

    // Direction of the step (1 or -1 for each axis)
    int stepX, stepY;
    int hit = 0;  // Was there a wall hit?
    int side;     // Was the wall hit on the X or Y side?

    // Calculate step and initial sideDist
    if (rayDirX < 0) {
        stepX = -1;
        sideDistX = (playerX - mapX) * deltaDistX;
    } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - playerX) * deltaDistX;
    }
    if (rayDirY < 0) {
        stepY = -1;
        sideDistY = (playerY - mapY) * deltaDistY;
    } else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - playerY) * deltaDistY;
    }

    // Perform DDA (Digital Differential Analyzer) to find the wall hit
    while (hit == 0) {
        // Jump to the next square (either in X or Y direction)
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0; // Hit a wall in the X direction
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1; // Hit a wall in the Y direction
        }

        // Check if we've hit a wall
        if (worldMap[mapY][mapX] > 0) hit = 1;
    }

    // Calculate the distance to the point of impact perpendicular to the player's view
    if (side == 0) perpWallDist = (mapX - playerX + (1 - stepX) / 2) / rayDirX;
    else           perpWallDist = (mapY - playerY + (1 - stepY) / 2) / rayDirY;

    // Calculate the height of the wall on screen
    int lineHeight = (int)(screenHeight / perpWallDist);

    // Calculate the top and bottom pixel to draw the wall
    int drawStart = -lineHeight / 2 + screenHeight / 2;
    if (drawStart < 0) drawStart = 0;
    int drawEnd = lineHeight / 2 + screenHeight / 2;
    if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

    // Set the wall color based on the direction
    if (side == 0) {
        // X-direction wall (facing EAST or WEST)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for EAST/WEST
    } else {
        // Y-direction wall (facing NORTH or SOUTH)
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue for NORTH/SOUTH
    }

    // Draw the vertical line for the wall
    SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
}

// Render the entire scene using raycasting
void renderScene(SDL_Renderer* renderer) {
    for (int x = 0; x < screenWidth; x++) {
        castRay(renderer, x); // Cast a ray for each column of the screen
    }

    SDL_RenderPresent(renderer); // Update the renderer with the new frame
}
