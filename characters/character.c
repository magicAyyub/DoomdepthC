//
// Created by ayyub on 10/2.txt/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "character.h"

#define DIRECTORY "../characters/"
#define TEXT_DIRECTORY "../game_texts/"
#define MONSTERS "monsters/"
#define PLAYERS "players/"
#define INITIAL 0
#define CHARACTER_MAX_HEIGHT 25

Monster *createMonster(int monsterId){
    Monster *monster =  malloc(sizeof(Monster));
    monster->base.x = 130;
    monster->base.y = 130;
    char *fileName = malloc(sizeof(char) * (strlen(MONSTERS) + strlen(DIRECTORY) + 1));
    strcpy(fileName, MONSTERS); // ex: "characters/monsters/"
    char *suffix = malloc(sizeof(char) * 8);
    sprintf(suffix, "%d.txt", monsterId); // ex: "2.txt.txt"
    strcat(fileName, suffix); // ex: "characters/monsters/2.txt.txt"
    readAsciiArtFromFile(fileName, &monster->base);
    free(fileName);
    free(suffix);

    generateRandomMonsterStats(monster); // generate random stats

    return monster;
}

Player *createPlayer(int playerId){
    Player *player =  malloc(sizeof(Player));
    player->base.x = 5;
    player->base.y = 5;
    char *fileName = malloc(sizeof(char) * (strlen(PLAYERS) + strlen(DIRECTORY) + 1));
    strcpy(fileName, PLAYERS); // ex: "characters/players/"
    char *suffix = malloc(sizeof(char) * 8);
    sprintf(suffix, "%d.txt", playerId); // ex: "2.txt.txt"
    strcat(fileName, suffix); // ex: "characters/players/2.txt.txt"
    readAsciiArtFromFile(fileName, &player->base);
    free(fileName);
    free(suffix);

    initPlayerStats(player); // give a default stat to player
    return player;
}

void initPlayerStats(Player *player){
    player->health = 100;
    player->attack = 10; // attack between 1 et 20
    player->defense = 10; // defense between 1 et 20
    player->speed = 5; // speed between 1 et 10
}

void generateRandomMonsterStats(Monster *monster) {
    srand(time(NULL)); // init a timer for a random value
    monster->health = rand() % 100 + 1; // health between 1 et 100
    monster->attack = rand() % 20 + 1; // attack between 1 et 20
    monster->defense = rand() % 20 + 1; // defense between 1 et 20
    monster->speed = rand() % 10 + 1; // speed between 1 et 10
}
void readAsciiArtFromFile(const char *asciiFileName, BaseCharacter *baseOfCharacter)
{
    char *fileName = malloc(sizeof(char) * (strlen(asciiFileName) + strlen(DIRECTORY) + 1));
    strcpy(fileName, DIRECTORY); // ex:  "characters/"
    strcat(fileName, asciiFileName); // ex: "characters/monsters/2.txt"

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
    baseOfCharacter->asciiArt = malloc(sizeof(char) * count);
    strcpy(baseOfCharacter->asciiArt, string);

    fclose(f);
    free(fileName); //
    free(string); // free the memory allocated for string
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


void displayCharacter(BaseCharacter character) {
    // Print the character's ASCII art
    printf("%s", character.asciiArt);
}


void freeMonster(Monster *monster){
    freeAsciiArt(&monster->base);
    free(monster);
}

void freePlayer(Player *player){
    freeAsciiArt(&player->base);
    free(player);
}
void freeAsciiArt(BaseCharacter *baseOfCharacter){
    free(baseOfCharacter->asciiArt);
}