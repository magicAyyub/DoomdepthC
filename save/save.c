//
// Created by ayyub on 10/22/2023.
//
#include <stdio.h>
#include "save.h"
void saveGame(Player player, Monster monsters[], int numMonsters, int currentZone) {
    FILE* file = fopen("savegame.txt", "w");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier de sauvegarde.\n");
        return;
    }

    struct SaveData {
        Player player;
        Monster monsters[MAX_MONSTERS];
        int numMonsters;
        int currentZone;
    } saveData;

    saveData.player = player;
    saveData.numMonsters = numMonsters;
    saveData.currentZone = currentZone;
    for (int i = 0; i < numMonsters; i++) {
        saveData.monsters[i] = monsters[i];
    }

    fwrite(&saveData, sizeof(struct SaveData), 1, file);
    fclose(file);

    printf("Partie sauvegardée avec succès.\n");
}


SaveData loadGame() {
    FILE* file = fopen("savegame.txt", "r");
    SaveData saveData;

    if (file == NULL) {
        printf("Aucune partie sauvegardée n'a été trouvée.\n");
        saveData.player = initializePlayer();
        return saveData;
    }

    fread(&saveData, sizeof(SaveData), 1, file);
    fclose(file);

    printf("Partie chargée avec succès.\n");

    return saveData;
}