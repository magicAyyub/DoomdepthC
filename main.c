#include<stdio.h>

#include "console/console.h"
#include "game/game.h"

// cd '~\Documents\ESGI - BACHELOR\DoomdepthC - Beta\cmake-build-debug'

int main() {

    displayHomeBanner();
    Monsters monsters = initializeMonsters(1);
    Player player = initializePlayer();

    printf("\n 1. Commencer une nouvelle partie\n 2. Restaurer une partie\n 3. Quitter");
    makeSpace(2);
    short choice = handleChoice(">> ",1,3);

    switch (choice) {
        case 1:
            clearScreen();
            int isPlayerWin = playerTour(&monsters,&player);

            if (isPlayerWin)
                printf("Vous passez a la prochaine zone");
            break;
        case 2:
            //
            break;
        case 3:
            printf("See you soon !");
            break;
    }
    return 0;
}






