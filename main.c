#include<stdio.h>
#include "characters/character.h"


int main() {

    // CREATE A MONSTER
    Monster *monster = createMonster(1); // monsterId => ascii file name (ex: 1.txt)

    printf("%s\n", monster->base.asciiArt);
    printf("Attack : %d\n", monster->attack);
    // ...
    freeMonster(monster);

    // CREATE A PLAYER
    Player *player = createPlayer(1);
    printf("%s\n", player->base.asciiArt);
    printf("Attack : %d\n", player->attack);
    // ...
    freePlayer(player);

    return 0;
}





