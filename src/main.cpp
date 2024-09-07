#include <SDL2/SDL.h>
#include "raycaster.h"
#include "render.h"
#include "input_handler.h"
#include "movement.h"
#include "collision.h" // Include the new collision header

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Make window
    window = SDL_CreateWindow("SDL2 Raycasting Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Make renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // The main loop flag
    bool quit = false;
    SDL_Event e;

    // The main application loop
    while (!quit) {
        // Handle input
        handleInput(&e, quit);

        // Render the scene
        renderScene(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
