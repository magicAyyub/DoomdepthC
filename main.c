#include<stdio.h>

#include "console/console.h"
#include "game/game.h"


// cd '~\Documents\ESGI - BACHELOR\DoomdepthC - Beta\cmake-build-debug'

int main() {

    displayHomeBanner();
    Monsters monsters = initializeMonsters(1);
    Player player = initializePlayer();
    Carte carte = initialiseCarte();

    printf("\n 1. Commencer une nouvelle partie\n 2. Restaurer une partie\n 3. Quitter");
    makeSpace(2);
    short choice = handleChoice(">> ",1,3);
    clearConsole();
    switch (choice) {
        case 1:
            play(&monsters, &player, &carte);
            break;
        case 2:
            player = loadGame(&player);
            displayPlayerPreviousData(&player);
            sleep_(2000);
            play(&monsters, &player, &carte);
            break;
        case 3:
            printf("Bye !");
            break;
    }
    return 0;
}






