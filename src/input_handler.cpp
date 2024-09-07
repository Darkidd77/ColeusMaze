#include "input_handler.h"
#include "raycaster.h"
#include "movement.h"

// Rotate the camera and move the player
void handleInput(SDL_Event *e, bool &quit) {
    while (SDL_PollEvent(e) != 0) {
        if (e->type == SDL_QUIT) {
            quit = true;
        } else if (e->type == SDL_KEYDOWN) {
            switch (e->key.keysym.sym) {
                case SDLK_LEFT:
                    // Rotate player left
                    playerAngle -= 0.1f;
                    if (playerAngle < 0) playerAngle += TWO_PI;
                    break;
                case SDLK_RIGHT:
                    // Rotate player right
                    playerAngle += 0.1f;
                    if (playerAngle > TWO_PI) playerAngle -= TWO_PI;
                    break;
                case SDLK_w:
                    movePlayer('W'); // Move forward
                    break;
                case SDLK_s:
                    movePlayer('S'); // Move backward
                    break;
                case SDLK_a:
                    movePlayer('A'); // Strafe left
                    break;
                case SDLK_d:
                    movePlayer('D'); // Strafe right
                    break;
            }
        } else if (e->type == SDL_MOUSEMOTION) {
            int x;
            SDL_GetMouseState(&x, NULL);
            playerAngle += (x - 640) * 0.002f; // Adjust sensitivity as needed
            if (playerAngle < 0) playerAngle += TWO_PI;
            if (playerAngle > TWO_PI) playerAngle -= TWO_PI;
            SDL_WarpMouseInWindow(NULL, 640, 360); // Reset mouse position to center
        }
    }
}
