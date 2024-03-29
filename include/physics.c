#ifndef PHYSICS_C
#define PHYSICS_C
#include "physics.h"

#include "gamedefinitions.h"
#include "gamescreen.h"

int checkCollision(char screen[SCREEN_HEIGHT][SCREEN_LENGTH], int x, int y){
    return (screen[y][x] == WALL || y < 0 ||
            y >= SCREEN_HEIGHT || x < 0 || x >= SCREEN_LENGTH) ? 1 : 0;
}

#endif