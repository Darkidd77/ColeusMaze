#include "collision.h"
#include "raycaster.h"

// Simple map for collision detection
// 0 empty space; 1 wall
int map[10][10] = {
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

// if position is within a wall
bool checkCollision(float newX, float newY) {
    int mapX = static_cast<int>(newX);
    int mapY = static_cast<int>(newY);

    // if the new position collides with a wall
    if (map[mapY][mapX] == 1) {
        return true; // Collision detected
    }
    return false; // No collision
}

// Handle the collision response by sliding the player along the wall
void handleCollision(float& playerX, float& playerY, float newX, float newY) {
    if (checkCollision(newX, newY)) {
        // Attempt to move only along X axis
        if (!checkCollision(newX, playerY)) {
            playerX = newX;
        }
        // Attempt to move only along Y axis
        else if (!checkCollision(playerX, newY)) {
            playerY = newY;
        }
        // If both are blocked, don't move
    } else {
        // No collision, move freely
        playerX = newX;
        playerY = newY;
    }
}
