#include "window.h"
#include "game.h"

const int SCREEN_WIDTH = 1260;
const int SCREEN_HEIGHT = 720;
const char* WINDOW_TITLE = "ColeusMaze";

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // Init SDL and create a window
    if (!initSDL(window, renderer, WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT)) {
        return 1;
    }

    // The Main game loop
    runGame(window, renderer);

    // Cleanup
    closeSDL(window, renderer);

    return 0;
}
