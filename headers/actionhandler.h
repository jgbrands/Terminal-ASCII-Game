#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "physics.h"
#include "mainmenu.h"
#include "plib.h"
#include "gamedefinitions.h"
#include "gamescreen.h"
#define ESC 27

void mainMenu();//For some goddamn reason if I don't put this prototype here
                //the compiler warns about implicit declaration on line 32;

Coord playerAction(char screen[SCREEN_HEIGHT][SCREEN_LENGTH], Player* player){
    switch (getch()){
    case ESC:
        system("cls");
        printf("Back to main menu\n");
        mainMenu();
        break;
    
    case 'w':
        if(!checkCollision(screen, player->coord.x, player->coord.y-1)){
            /* gotoxy(2 * player->coord.x, player->coord.y--);
            printf("%c", FLOOR);
            gotoxy(2 * player->coord.x, player->coord.y);
            printf("%c", PLAYER); */
            Coord prevCoord;
            prevCoord.x = player->coord.x;
            prevCoord.y = player->coord.y;
            player->coord.y--;
            return prevCoord;
        }else return player->coord;
        break;

    case 'a':
        if(!checkCollision(screen, player->coord.x-1, player->coord.y)){
            /* gotoxy(2 * player->coord.x--, player->coord.y);
            printf("%c", FLOOR);
            gotoxy(2 * player->coord.x, player->coord.y);
            printf("%c", PLAYER); */
            Coord prevCoord;
            prevCoord.x = player->coord.x;
            prevCoord.y = player->coord.y;
            player->coord.x--;
            return prevCoord;
        }else return player->coord;
        break;

    case 's':
        if(!checkCollision(screen, player->coord.x, player->coord.y+1)){
            /* gotoxy(2 * player->coord.x, player->coord.y++);
            printf("%c", FLOOR);
            gotoxy(2 * player->coord.x, player->coord.y);
            printf("%c", PLAYER); */
            Coord prevCoord;
            prevCoord.x = player->coord.x;
            prevCoord.y = player->coord.y;
            player->coord.y++;
            return prevCoord;
        }else return player->coord;
        break;

    case 'd':
        if(!checkCollision(screen, player->coord.x+1, player->coord.y)){
            /* gotoxy(2 * player->coord.x++, player->coord.y);
            printf("%c", FLOOR);
            gotoxy(2 * player->coord.x, player->coord.y);
            printf("%c", PLAYER); */
            Coord prevCoord;
            prevCoord.x = player->coord.x;
            prevCoord.y = player->coord.y;
            player->coord.x++;
            return prevCoord;
        }else return player->coord;
        break;

    case '\r':
        system("cls");
        printf("Menu\n");
        break;

    case 'r':
        system("cls");
        renderGameScreen();
        break;

    default:
        playerAction(screen, player);
        break;
    }
}

#endif