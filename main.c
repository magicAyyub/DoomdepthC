#include<stdio.h>
#include "characters/character.h"

int main() {

    displayTextFromFile("startBanner");
    short choice;
    printf("\n\n1 - Start\n\n2 - Quit\n>> ");
    scanf("%hd",&choice);

    if (choice == 1){
        // CREATE A PLAYER
        Player *player = createPlayer(1);
        displayCharacter(player->base);

        // CREATE A MONSTER
        Monster *monster = createMonster(1); // monsterId => ascii file name (ex: 1.txt)
        displayCharacter(monster->base);

        freePlayer(player);
        freeMonster(monster);
    }
    else
        printf("A TRES BIENTOT !");
    return 0;

}