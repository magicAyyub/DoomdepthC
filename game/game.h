//
// Created by ayyub on 10/22/2023.
//
#ifndef GAME_H
#define GAME_H

#include "../console/console.h"
#include "../fights/fights.h"
#include "../items/items.h"
#define MAX_MONSTERS 4
#define LEN(x) (sizeof(x) / sizeof((x)[0]))
#define TEXT_DIRECTORY "../texts/"
#define MAP_WIDTH 500
#define MAP_HEIGHT 500


void playTurn(Player *player, Monster monsters[],int numMonsters, int monsterDifficulty);
Monsters getMonsters(int difficulty);
void displayTextFromFile(const char *asciiFileName);
void displayHomeBanner();

#endif