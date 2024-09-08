#include "render.h"
#include "raycaster.h"

// Draw walls (0 for N/S walls, 1 for E/W walls)
void drawWalls(SDL_Renderer* renderer, int x, int drawStart, int drawEnd, int side) {
    if (side == 0) {
        // North-South facing walls: Red
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    } else {
        // East-West facing walls: Green
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    }
    SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
}

// Render all walls in the scene
void renderWalls(SDL_Renderer* renderer, int map[MAP_HEIGHT][MAP_WIDTH], int screenWidth, int screenHeight, float playerX, float playerY, float playerAngle) {
    for (int x = 0; x < screenWidth; x++) {
        // Use the raycasting function to calculate the position of walls
        float rayAngle = playerAngle + atan((x - screenWidth / 2) / screenWidth);
        int side = 0;  // 0 for N/S, 1 for E/W walls (this can come from raycasting logic)

        // Here, you should calculate where the walls start and end based on raycasting
        int drawStart = 100;  // Placeholder
        int drawEnd = 600;    // Placeholder

	// Assume side is calculated as part of the raycasting logic
        drawWalls(renderer, x, drawStart, drawEnd, side);
    }
    SDL_RenderPresent(renderer);  // Update the screen after drawing
}
