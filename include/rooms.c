#ifndef ROOMS_C
#define ROOMS_C
#include "rooms.h"

#include "gamedefinitions.h"
#include <time.h>
#include <stdlib.h>

void generateRoom(char screen[SCREEN_HEIGHT][SCREEN_LENGTH], int x, int y, int length, int height){
    length += x;
    height += y;
    for (x = x; x <= length; x++){
        screen[y][x] = WALL;
        screen[height][x] = WALL;
    }for (y += 1, x -= (length/2) + 1; y < height; y++){
        screen[y][x] = WALL;
        screen[y][length] = WALL;
    }

    srand(time(0));
    screen[y][(rand() % ((length)/2 - 1)) + (x + 1)] = DOOR;
}

#endif