//
// Created by ayyub on 10/22/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

int playerTour(Monsters *monsters, Player *player){

    if (monsters->numberOfMonster > 1)
        printf("\n\t %s Des monstres apparaissent !%s\n\n",TC_YEL,RESET);
    else
        printf("\n\t %s Un monstre apparait !%s\n\n",TC_YEL,RESET);

    displayAllMonstersSkin(monsters);

    makeSpace(3);

    int life = getPercentage(player->life,player->total_life);
    int mana = getPercentage(player->mana,100);

    displayPlayerSkin(life, mana);

    makeSpace(3);

    printf("\n %s Vous pouvez faire au maximum %d actions par tour.%s\n",TC_YEL,player->attacks_per_turn,RESET);
    for (int i = 1;  i <= player->attacks_per_turn;i++){
        printf("\n %s %sAction %d %s\n",TC_BG_BLU,TC_WHT,i,RESET);
        playerTurn(player,monsters);
        if (monsters->numberOfMonster <=0)
            break;
    }

    if (monsters->numberOfMonster<=0) {
        makeSpace(2);
        printf("%s %sVous avez gagne !%s", TC_BG_GRN, TC_WHT, RESET);
        return 1;
    } else {
        return 0;
    }
}




short handleChoice(const char *prompt, int min_value, int max_value){
    printf("%s",prompt);
    short choice;
    while(1){
        scanf("%hd", &choice);
        if (choice >= min_value && choice <= max_value)
            return choice;
        else
            printf("Choix invalide, veuillez reessayer : ");
    }

}


void readjustMonsters(Monsters *monsters,int monsterDiedPosition){
    monsters->numberOfMonster--;
    deleteMonsterDied(&monsters->monsters[monsterDiedPosition],monsters->numberOfMonster,monsterDiedPosition);

}

void deleteMonsterDied(Monster *monsters,int numberOfMonster,int monsterDiedPosition){
    for (int i = monsterDiedPosition; i < numberOfMonster; i++)
        *(monsters + i) = *(monsters + (i+1));
}

void playerTurn(Player *player, Monsters *monsters)
{
    printf("Que voulez-vous faire ?\n 1. Attaquer\n 2. Fuir\n 3. objets\n");
    short choice = handleChoice(">> ",1,3);

    switch (choice) {
        case 1:
            printf("\n");
            attackOnMonster(player, monsters);
            break;
        case 2:
            //
            break;
        case 3:
            displayInventory(player);
            break;
    }
}

void makeSpace(int offset){
    for (int i=0; i<offset; i++)
        printf("\n");
}


void displayTextFromFile(const char *asciiFileName)
{
    char *fileName = malloc(sizeof(char) * (strlen(asciiFileName) + strlen(TEXT_DIRECTORY) + 1));
    strcpy(fileName, TEXT_DIRECTORY);
    strcat(fileName, asciiFileName);


    FILE *f = fopen(fileName, "rb");

    if (f == NULL) {
        printf("File not found");
        free(fileName);
        return;
    }

    fseek(f, 0, SEEK_END); // seek to end of file
    long count = ftell(f);  // get current file pointer (number of bytes)
    fseek(f, 0, SEEK_SET);  // seek back to beginning of file

    char *string = malloc(count + 1);
    fread(string, 1, count, f);

    string[count] = '\0';
    char*text = malloc(sizeof(char) * count);
    strcpy(text, string);
    printf("%s",text);

    fclose(f);
    free(fileName); //
    free(string); // free the memory allocated for string
    free(text);

}

void displayHomeBanner()
{
    printf(BLUE);
    displayTextFromFile("menuBanner");
    printf(RESET);
    printf("\n");
    // Print "DOOMDEPTHS" in ASCII art with colors
    printf(RED);
    printf("______ _____  ________  ________ ___________ _____ _   _  _____ \n");
    printf("|  _  \\  _  ||  _  |  \\/  |  _  \\  ___| ___ \\_   _| | | |/  ___|\n");
    printf(BRIGHT_RED);
    printf("| | | | | | || | | | .  . | | | | |__ | |_/ / | | | |_| |\\ `--. \n");
    printf("| | | | | | || | | | |\\/| | | | |  __||  __/  | | |  _  | `--. \\\n");
    printf(RESET);
    printf("| |/ /\\ \\_/ /\\ \\_/ / |  | | |/ /| |___| |     | | | | | |/\\__/ /\n");
    printf("|___/  \\___/  \\___/\\_|  |_/___/ \\____/\\_|     \\_/ \\_| |_/\\____/ \n");
    printf("\n");
}