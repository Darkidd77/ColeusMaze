#include "game.h"
#include "raycaster.h"
#include "window.h"

void runGame(SDL_Window* window, SDL_Renderer* renderer) {
    bool quit = false;
    SDL_Event e;

    // Player var
    float playerX = 5.0f;  // Start X position
    float playerY = 5.0f;  // Start Y position
    float playerAngle = 0.0f; // Start angle

    // The Main application loop
    while (!quit) {
        // To Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // Quit Request
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                // Handle player movement
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        playerAngle -= 0.1; // Rotate left
                        break;
                    case SDLK_RIGHT:
                        playerAngle += 0.1; // Rotate right
                        break;
                    case SDLK_UP:
                        playerX += cos(playerAngle) * 0.5;
                        playerY += sin(playerAngle) * 0.5;
                        break;
                    case SDLK_DOWN:
                        playerX -= cos(playerAngle) * 0.5;
                        playerY -= sin(playerAngle) * 0.5;
                        break;
                }
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255); // Sky blue color for ceiling
        SDL_RenderClear(renderer);

        // Render walls using raycasting
        renderWalls(renderer, (int (*)[MAP_WIDTH])map, 1260, 720, playerX, playerY, playerAngle);

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    // Clean up before exiting
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
