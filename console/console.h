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


enum ConsoleColor{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void sleep_(int milliseconds);
void clear_screen();
void clear_lines(int lines);
void clear_stdin();
int actualStringLength(const char *str);
void wait_for_enter();


#endif //DOOMDEPTHC_CONSOLE_H
