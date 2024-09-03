#include "raycaster.h"
#include "game.h"
#include <cmath>

#define PI 3.14159265358979323846

// Function to raycasting and render walls
void renderWalls(SDL_Renderer* renderer, int map[MAP_HEIGHT][MAP_WIDTH], int screenWidth, int screenHeight, float playerX, float playerY, float playerAngle) {
    // Def variables
    int rayCount = screenWidth; // Number of rays is equal to screen width
    float rayAngleStep = PI / 3 / rayCount; // Field of view is 60 degrees

    for (int ray = 0; ray < rayCount; ++ray) {
        float rayAngle = playerAngle - (PI / 6) + ray * rayAngleStep; // Calculate current ray angle
        float distanceToWall = 0;
        bool hitWall = false;
        float eyeX = cos(rayAngle);
        float eyeY = sin(rayAngle);

        while (!hitWall && distanceToWall < 30) { // Max distance
            distanceToWall += 0.1; // Move forward along the ray

            int testX = static_cast<int>(playerX + eyeX * distanceToWall);
            int testY = static_cast<int>(playerY + eyeY * distanceToWall);

            if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT) {
                hitWall = true; // Ray is out of bounds
                distanceToWall = 30; // Max distance for out of bounds
            } else {
                // Test if the ray is hitting a wall
                if (map[testY][testX] == 1) {
                    hitWall = true; // Ray hit a wall
                }
            }
        }

        // Calculate wall height based on distance
        int wallHeight = static_cast<int>(screenHeight / distanceToWall);

        // Calculate color shade based on distance (closer walls are brighter)
        int shade = 255 - (distanceToWall * 8);
        if (shade < 0) shade = 0;

        SDL_SetRenderDrawColor(renderer, shade, shade / 2, shade / 4, 255); // Set wall color
        SDL_RenderDrawLine(renderer, ray, (screenHeight - wallHeight) / 2, ray, (screenHeight + wallHeight) / 2); // Draw wall slice
    }
}
