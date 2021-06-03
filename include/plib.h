#ifndef PLIB_H
#define PLIB_H

//Clears the remaining characters until and including the newline;
void clearInput();

//Forces the user to enter the specified char;
void forceCharInput(char c);

#define PLIB_MAX_PASSWORD_LENGTH 20
char password[PLIB_MAX_PASSWORD_LENGTH];
//Requests a password from the user and stores it in the specified variable;
//MAX_PASSWORD_LENGTH determines the maximum size of the input;
char* requestPassword();

//Moves the console cursor to the specified coordinates;
void gotoxy(int a, int b);

//Makes the console cursor not visible;
void hideCursor();

//Cabeçalho dos trabalhos da UFPI;
void UFPIcab();

#endif