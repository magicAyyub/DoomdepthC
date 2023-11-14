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


// Function to clear the console screen
void clearConsole() {
#ifdef _WIN32
    system("cls");  // For Windows
#else
    system("clear");  // For Unix-like systems (Linux, macOS)
#endif
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

short handleChoice(const char *prompt, int min_value, int max_value){
    printf("%s",prompt);
    short choice;
    while(1){
        scanf("%hd", &choice);
        if (choice >= min_value && choice <= max_value)
            return choice;
        else
            printf("Choix invalide, veuillez reessayer : ");
    }

}

int handleYesOrNo(const char *prompt){
    printf("%s",prompt);
    while (1) {
        char answer;
        scanf(" %c", &answer);  // Note the space before %c to consume any leading whitespace

        answer = tolower(answer);

        if (answer == 'o')
            return 1;
        else if (answer == 'n')
            return 0;
        else if (answer == 'q')
            return -1;
        else
            printf("Choix invalide, veuillez reessayer : ");

    }

}

void makeSpace(int offset){
    for (int i=0; i<offset; i++)
        printf("\n");
}

