//
// Created by ayyub on 10/22/2023.
//
//
// Created by ayyub on 10/22/2023.
//
#ifndef SAVE_H
#define SAVE_H
#include "../game/game.h"

void saveGame(Player *player);
Player loadGame(Player *player);
int savePlayerData(Player *playerData, const char *filename);
int loadPlayerData(Player *playerData, const char *filename);
int saveMonsterData(Monsters *monsterData, const char *filename);
int loadMonsterData(Monsters *monsterData, const char *filename);
#endif