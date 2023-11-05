//
// Created by ayyub on 10/22/2023.
//
#include <stdio.h>
#include <string.h>
#include "map.h"
#define MAX_ZONES 10

void initializeGameZones(GameZone gameZones[]) {

    strcpy(gameZones[0].name, "Forêt mystérieuse");
    gameZones[0].level = 1;
    gameZones[0].numMonsters = 3;
    gameZones[0].maxMonsters = 5;

    strcpy(gameZones[1].name, "Grotte sombre");
    gameZones[1].level = 2;
    gameZones[1].numMonsters = 5;
    gameZones[1].maxMonsters = 7;

    // d'autres zones
}


void displayGameZones(GameZone gameZones[], int currentZone) {
    printf("Zones du jeu :\n");
    for (int i = 0; i < MAX_ZONES; i++) {
        if (i == currentZone) {
            printf("-> ");
        } else {
            printf("  ");
        }
        printf("%d. %s (niveau %d)\n", i + 1, gameZones[i].name, gameZones[i].level);
    }
}
