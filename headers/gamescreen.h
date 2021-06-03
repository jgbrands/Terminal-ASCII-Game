#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <windows.h>

void renderGameScreen();

void gameStart(){
    system("cls");
    renderGameScreen();
}

#include <stdio.h>
#include "actionhandler.h"
#include "plib.h"
#include "gamedefinitions.h"
#include "rooms.h"
#include "cave.h"
#include "fov.h"

void updateScreen(Player, Coord);

void renderGameScreen(){
    int** cave = generateCave(SCREEN_HEIGHT, SCREEN_LENGTH, 63, 4, 5);
    char screen[SCREEN_HEIGHT][SCREEN_LENGTH];

    int i;
    for (i = 0; i < SCREEN_HEIGHT; i++){
        int j;
        for (j = 0; j < SCREEN_LENGTH; j++){
            if(cave[i][j] == 1){
                screen[i][j] = WALL;
            }
            else if(cave[i][j] == 0){
                screen[i][j] = UNSEEN;
            }
            else{
                printf("ih, deu merda mermao k k k\n");
                exit(0);
            }

            if(i == 0 || i == SCREEN_HEIGHT - 1 || j == 0 || j == SCREEN_LENGTH -1){
                screen[i][j] = WALL;
            }
        }
    }

    //Spawn player;
    Player player;
    int end = 0;
    for(i = 0; i < SCREEN_HEIGHT; i++){
        if(end == 1) break;
        int j;
        for(j = 5; j < SCREEN_LENGTH; j++){
            if(end == 1) break;
            if(screen[i][j] != WALL){
                player.coord.x = j;
                player.coord.y = i;
                end = 1;
                break;
            }
        }
    }
    screen[player.coord.y][player.coord.x] = PLAYER;
    //generateRoom(screen, 5, 5, 5, 5);

    //Print the base screen;
    hideCursor();
    for (i = 0; i < SCREEN_HEIGHT; i++){
        int j;
        for (j = 0; j < SCREEN_LENGTH; j++){
            printf("%c ", screen[i][j]);
        }
        printf("\n");
    }
    //Update the screen;
    Coord prevCoord;
    while(1){
        prevCoord = playerAction(screen, &player);
        updateScreen(player, prevCoord);
    }

}//cd Desktop\CompSci\Projects\ADungeon & gcc -std=c99 adungeon.c -o adungeon && adungeon

void updateScreen(Player player, Coord prevCoord){
    gotoxy(2 * prevCoord.x, prevCoord.y);
    printf("%c", FLOOR);
    gotoxy(2 * player.coord.x, player.coord.y);
    printf("%c", PLAYER);
}

#endif