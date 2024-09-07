#include "movement.h"
#include "raycaster.h"
#include "collision.h"

// Player movement speed
const float moveSpeed = 0.1f;

// Player movement function
void movePlayer(char direction) {
    float newX = playerX;
    float newY = playerY;

    // New position based on direction
    if (direction == 'W') { // Move forward
        newX += cos(playerAngle) * moveSpeed;
        newY += sin(playerAngle) * moveSpeed;
    } else if (direction == 'S') { // Move backward
        newX -= cos(playerAngle) * moveSpeed;
        newY -= sin(playerAngle) * moveSpeed;
    } else if (direction == 'A') { // Move left (strafe)
        newX -= cos(playerAngle + PI / 2) * moveSpeed;
        newY -= sin(playerAngle + PI / 2) * moveSpeed;
    } else if (direction == 'D') { // Move right (strafe)
        newX += cos(playerAngle + PI / 2) * moveSpeed;
        newY += sin(playerAngle + PI / 2) * moveSpeed;
    }

    // Collision with walls
    handleCollision(playerX, playerY, newX, newY);
}
