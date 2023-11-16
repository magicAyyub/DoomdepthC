#include <stdio.h>
#include "save.h"
void saveGame(Player *player) {

    if (savePlayerData(player, "player.dat") != 0)
        fprintf(stderr, "Error saving player data.\n");
    printf("%s Votre partie a bien ete sauvegarde%s",TC_YEL,RESET);
}

Player loadGame(Player *player) {

    if (loadPlayerData(player, "player.dat") != 0)
        printf("Une erreur s'est produite lors du chargement des donnees du joueur.\n");
    else
        return *player;
}


int savePlayerData(Player *playerData, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(playerData, sizeof(Player), 1, file);
        fclose(file);
    } else {
        printf("Erreur lors de l'ouverture du fichier pour sauvegarde.\n");
        return 1;
    }
    return 0;
}

int loadPlayerData(Player *playerData, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        fread(playerData, sizeof(Player), 1, file);
        fclose(file);
    } else {
        printf("Erreur lors de l'ouverture du fichier pour lecture.\n");
        return 1;
    }
    return 0;
}
