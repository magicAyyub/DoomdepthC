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


void playerTurn(Player *player, Monsters *monsters);
short handleChoice(const char *prompt, int min_value, int max_value);
void deleteMonsterDied(Monster *monsters,int numberOfMonster,int monsterDiedPosition);
void readjustMonsters(Monsters *monsters,int monsterDiedPosition);
void makeSpace(int offset);
Monsters initializeMonsters(int difficulty);
void displayTextFromFile(const char *asciiFileName);
void displayHomeBanner();
int playerTour(Monsters *monsters, Player *player);


#endif