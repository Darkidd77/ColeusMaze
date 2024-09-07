#include "render.h"

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
