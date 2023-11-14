//
// Created by ayyub on 10/22/2023.
//
#ifndef GAME_H
#define GAME_H

#include "../console/console.h"
#include "../fights/fights.h"
#include "../items/items.h"
#include "../save/save.h"
#include "../map/map.h"
#define MAX_MONSTERS 3
#define LEN(x) (sizeof(x) / sizeof((x)[0]))
#define TEXT_DIRECTORY "../texts/"
#define MAP_WIDTH 500
#define MAP_HEIGHT 500


void playerTurn(Player *player, Monsters *monsters);
void deleteMonsterDied(Monsters *monsters,int monsterDiedPosition);
void readjustMonsters(Monsters *monsters,int monsterDiedPosition);
Monsters initializeMonsters(int difficulty);
void displayTextFromFile(const char *asciiFileName);
void displayHomeBanner();
int playerTour(Monsters *monsters, Player *player, int isClean);
void displayPlayerPreviousData(Player *player);
int monstersTour(Monsters *monsters, Player *player);
void displayGameOver();
void displayWin();
void play(Monsters *monsters, Player *player, Carte *carte);
void displayAppearanceMessage(Monsters *monsters, int state);


#endif