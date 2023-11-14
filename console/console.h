//
// Created by ayyub on 11/1/2023.
//

#ifndef DOOMDEPTHC_CONSOLE_H
#define DOOMDEPTHC_CONSOLE_H


#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32 // Si windows
#include <windows.h>
#else
#include <unistd.h>
#endif

// Text color codes
#define TC_NRM  "\x1B[0m"
#define TC_RED  "\x1B[1;31m"
#define TC_GRN  "\x1B[1;32m"
#define TC_YEL  "\x1B[1;33m"
#define TC_BLU  "\x1B[1;34m"
#define TC_MAG  "\x1B[1;35m"
#define TC_CYN  "\x1B[1;36m"
#define TC_WHT  "\x1B[1;37m"

// Background color codes
#define TC_BG_NRM "\x1B[40m"
#define TC_BG_RED " \x1B[41m"
#define TC_BG_GRN "\x1B[42m"
#define TC_BG_YEL "\x1B[43m"
#define TC_BG_BLU "\x1B[44m"
#define TC_BG_MAG "\x1B[45m"
#define TC_BG_CYN "\x1B[46m"
#define TC_BG_WHT "\x1B[47m"

#define RED "\x1b[31m"
#define RED_2 "\x1b[38;5;196m"
#define RED_3 "\x1b[38;5;160m"
#define RED_4 "\x1b[38;5;124m"
#define RED_5 "\x1b[38;5;88m"
#define RED_6 "\x1b[38;5;52m"
#define BRIGHT_RED   "\x1b[1;31m"


#define RESET "\x1b[0m"


#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define BLACK "\x1b[30m"

#define clearScreen() printf("\e[1;1H\e[2J")
#define gotoPosition(X, Y) printf("\033[%d;%dH", Y, X)



void sleep_(int milliseconds);
void clear_stdin();
int actualStringLength(const char *str);
void clearConsole();
short handleChoice(const char *prompt, int min_value, int max_value);
int handleYesOrNo(const char *prompt);
void makeSpace(int offset);


#endif //DOOMDEPTHC_CONSOLE_H
