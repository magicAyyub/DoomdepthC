//
// Created by ayyub on 10/22/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

void playTurn(Player *player, Monster monsters[],int numMonsters, int monsterDifficulty)
{
    int choice;
    printf("Que voulez-vous faire ?\n");
    printf("1. Attaquer\n");
    printf("2. Consulter l'inventaire\n");
    printf("3. Quitter\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        attackOnPlayer(monsters, player, numMonsters);
        for (int i = 0; i < numMonsters; i++)
        {
            // Generate a unique seed for each monster
            unsigned int seed = (unsigned int)time(NULL) + i;
            if (monsters[i].life <= 0)
            {
                printf("Le monstre %d a été vaincu.\n", i + 1);
                player->gold += monsters[i].gold_reward;
                monsters[i] = generateMonster(monsterDifficulty,seed);
            }
        }
    }
    else if (choice == 2)
    {
        displayInventory(*player);
    }
    else
    {
        printf("Game over.\n");
        exit(0);
    }
}

void displayTextFromFile(const char *asciiFileName)
{
    char *fileName = malloc(sizeof(char) * (strlen(asciiFileName) + strlen(TEXT_DIRECTORY) + 1));
    strcpy(fileName, TEXT_DIRECTORY);
    strcat(fileName, asciiFileName);


    FILE *f = fopen(fileName, "rb");

    if (f == NULL) {
        printf("File not found");
        free(fileName);
        return;
    }

    fseek(f, 0, SEEK_END); // seek to end of file
    long count = ftell(f);  // get current file pointer (number of bytes)
    fseek(f, 0, SEEK_SET);  // seek back to beginning of file

    char *string = malloc(count + 1);
    fread(string, 1, count, f);

    string[count] = '\0';
    char*text = malloc(sizeof(char) * count);
    strcpy(text, string);
    printf("%s",text);

    fclose(f);
    free(fileName); //
    free(string); // free the memory allocated for string
    free(text);

}

void displayHomeBanner()
{
    printf(BLUE);
    displayTextFromFile("menuBanner");
    printf(RESET);
    printf("\n");
    // Print "DOOMDEPTHS" in ASCII art with colors
    printf(RED);
    printf("______ _____  ________  ________ ___________ _____ _   _  _____ \n");
    printf("|  _  \\  _  ||  _  |  \\/  |  _  \\  ___| ___ \\_   _| | | |/  ___|\n");
    printf(BRIGHT_RED);
    printf("| | | | | | || | | | .  . | | | | |__ | |_/ / | | | |_| |\\ `--. \n");
    printf("| | | | | | || | | | |\\/| | | | |  __||  __/  | | |  _  | `--. \\\n");
    printf(RESET);
    printf("| |/ /\\ \\_/ /\\ \\_/ / |  | | |/ /| |___| |     | | | | | |/\\__/ /\n");
    printf("|___/  \\___/  \\___/\\_|  |_/___/ \\____/\\_|     \\_/ \\_| |_/\\____/ \n");
    printf("\n");
}