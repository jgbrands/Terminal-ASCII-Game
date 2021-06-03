#ifndef MAINMENU_C
#define MAINMENU_C
#include "mainmenu.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "gamescreen.h"
#include "gamedefinitions.h"

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

#endif