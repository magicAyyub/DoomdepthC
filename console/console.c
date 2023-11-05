//
// Created by ayyub on 11/1/2023.
//

#include "console.h"

void sleep_(int milliseconds){
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        usleep(milliseconds * 1000);
    #endif
}

void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void clear_screen()
{
    printf("\e[1;1H\e[2J");
}

void clear_lines(int lines)
{
    for (int i = 0; i < lines; ++i)
        printf("\x1b[1F\x1b[2K");
}

void clear_line(int line)
{
    printf("\x1b[%d;0H", line); // Place le curseur à la ligne spécifiée
    printf("\x1b[2K"); // Efface la ligne actuelle
}
void wait_for_enter()
{
    printf("\nPress [ENTER] to continue...");
    clear_stdin();
}

int actualStringLength(const char *str)
{
    int length = 0;
    int inColorCode = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\x1B')
        { // Check for ANSI escape code
            inColorCode = 1;
        }
        else if (inColorCode && str[i] == 'm')
        {
            inColorCode = 0;
        }
        else if (!inColorCode)
        {
            length++;
        }
    }

    return length;
}
