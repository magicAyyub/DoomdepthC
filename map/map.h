//
// Created by ayyub on 10/22/2023.
//
#ifndef MAP_H
#define MAP_H
#include "../characters/character.h"

// Structure pour représenter une zone du jeu
typedef struct {
    char name[30];
    int level;
    int numMonsters;
    int maxMonsters;
} GameZone;

void initializeGameZones(GameZone gameZones[]);
void displayGameZones(GameZone gameZones[], int currentZone);

#endif
