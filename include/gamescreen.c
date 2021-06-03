#ifndef GAMESCREEN_C
#define GAMESCREEN_C
#include "gamescreen.h"

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

void updateScreen(Player, Coord);

void renderGameScreen(){
    char screen[SCREEN_HEIGHT][SCREEN_LENGTH];

    //Fill screen
    int i, j;
    for (i = 0; i < SCREEN_HEIGHT; i++){
        for (j = 0; j < SCREEN_LENGTH; j++){
            screen[i][j] = '.';
        }
    }
    
    //Spawn player
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
    generateRoom(screen, 5, 5, 5, 5);

    //Print the base screen
    hideCursor();
    for (i = 0; i < SCREEN_HEIGHT; i++){
        int j;
        for (j = 0; j < SCREEN_LENGTH; j++){
            printf("%c ", screen[i][j]);
        }
        printf("\n");
    }
    //Update the screen
    Coord prevCoord;
    while(1){
        prevCoord = playerAction(screen, &player);
        updateScreen(player, prevCoord);
    }

}

void updateScreen(Player player, Coord prevCoord){
    gotoxy(2 * prevCoord.x, prevCoord.y);
    printf("%c", FLOOR);
    gotoxy(2 * player.coord.x, player.coord.y);
    printf("%c", PLAYER);
}

#endif