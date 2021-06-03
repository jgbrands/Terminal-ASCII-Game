#ifndef GAME_DEFINITIONS_H
#define GAME_DEFINITIONS_H

/* #define SCREEN_LENGTH 105
#define SCREEN_HEIGHT 49 */
#define SCREEN_LENGTH 105
#define SCREEN_HEIGHT 49
#define PLAYER '@'
#define WALL '#'
#define FLOOR '.'
#define UNSEEN ' '
#define DOOR '+'

typedef struct Coord{
    int x;
    int y;
}Coord;

typedef struct Player{
    int health;
    int attack;
    Coord coord;
}Player;

#endif