#ifndef MAINMENU_H
#define MAINMENU_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "gamescreen.h"

void printMainMenu();

void mainMenu(){
    printMainMenu();

    if(getch() == ESC){
        system("cls");
        printf("Exited");
        exit(0);
    }
    else{
        printf("Game Start");
        gameStart();
    }
}

void printMainMenu(){
    printf("=======================================================================================================================\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                   ASCII                                                             |\n");
    printf("|                                                     Dungeon                                                         |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                             Press any key to start                                                  |\n");
    printf("|                                                Press ESC to exit                                                    |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("|                                                                                                                     |\n");
    printf("=======================================================================================================================\n");
}

#endif