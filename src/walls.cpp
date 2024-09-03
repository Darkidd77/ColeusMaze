#include "raycaster.h"
#include "game.h"
#include <cmath>


// Walls height based on distance
int wallHeight = static_cast<int>(screenHeight / distanceToWall);

// Calculate color shade based on distance
int shade = 255 - (distanceToWall * 8);
if (shade < 0) shade = 0;
SDL_SetRenderDrawColor(renderer, shade, shade / 2, shade / 4, 255);
SDL_RenderDrawLine(renderer, ray, (screenHeight - wallHeight) / 2, ray, (screenHeight + wallHeight) / 2); // Draw wall slice
    }
}
