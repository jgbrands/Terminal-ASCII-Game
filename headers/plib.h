#ifndef PERSONAL_H
#define PERSONAL_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//Clears the remaining characters until and including the newline;
void clearInput(){
    while(getchar() != '\n');
}

//Forces the user to enter the specified char;
void forceCharInput(char c){
    while(getch() != c);
}

#define PLIB_MAX_PASSWORD_LENGTH 20
char password[PLIB_MAX_PASSWORD_LENGTH];
//Requests a password from the user and stores it in the specified variable;
//MAX_PASSWORD_LENGTH determines the maximum size of the input;
char* requestPassword(){
    int i;
    for (i = 0; i < PLIB_MAX_PASSWORD_LENGTH; i++){
        password[i] = getch();
        if(password[i] == '\r'){
            password[i] = '\0';
            break;
        }
        printf("*");
    }
    printf("\n");

    return password;
}

//Moves the console cursor to the specified coordinates;
void gotoxy(int a, int b){
    COORD c;
    c.X=a;
    c.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Makes the console cursor not visible;
void hideCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

//Cabeçalho dos trabalhos da UFPI;
void UFPIcab(){
    printf("----------------------------------\n");
    printf("# Universidade Federal do Piaui\n");
    printf("# Ciencia da Computacao\n");
    printf("# Joao Gabriel Fernandes Brandao\n");
    printf("----------------------------------\n\n");
}

#endif