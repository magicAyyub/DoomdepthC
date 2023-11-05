//
// Created by ayyub on 10/22/2023.
//
#ifndef SAVE_H
#define SAVE_H
#include "../game/game.h"


// Structure pour sauvegarder les données du joueur
typedef struct {
    Player player;
    Monster monsters[10];
} SaveData;

void saveGame(Player player, Monster monsters[], int numMonsters, int currentZone);
SaveData loadGame();

#endif