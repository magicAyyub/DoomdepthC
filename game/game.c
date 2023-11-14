//
// Created by ayyub on 10/22/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

int playerTour(Monsters *monsters, Player *player, int isClean){
    if (isClean > 0) {
        sleep_(1000);
        //clearConsole();
    }

    printf("\n");
    displayAllMonstersSkin(monsters);

    sleep_(1000);

    int life = getPercentage(player->life,player->total_life);
    int mana = getPercentage(player->mana,10);

    printf("\n\t%sPreparez vous au combat !%s\n\n",TC_YEL,RESET);
    displayPlayerSkin(life, mana);
    sleep_(70);

    printf("\n\n %s Vous pouvez faire au maximum %d actions par tour.%s\n",TC_YEL,player->attacks_per_turn,RESET);
    for (int i = 1;  i <= player->attacks_per_turn;i++){
        printf("\n %s %sAction %d %s\n\n",TC_BG_BLU,TC_WHT,i,RESET);
        playerTurn(player,monsters);
        if (monsters->numberOfMonster <=0)
            return 1;

    }

    return 0;

}

int monstersTour(Monsters *monsters, Player *player){
    return attackOnPlayer(monsters,player);
}


void readjustMonsters(Monsters *monsters,int monsterDiedPosition){
    deleteMonsterDied(monsters,monsterDiedPosition);
    monsters->numberOfMonster--;

}

void deleteMonsterDied(Monsters *monsters,int monsterDiedPosition){
    for (int i = monsterDiedPosition; i < monsters->numberOfMonster; i++)
        *(monsters->monsters + i) = *(monsters->monsters + (i+1));
}

void playerTurn(Player *player, Monsters *monsters)
{
    printf("--> Que voulez-vous faire ?\n\n 1. Attaquer\n 2. Fuir\n 3. utiliser un objets\n");
    short choice = handleChoice(">> ",1,3);

    switch (choice) {
        case 1:
            printf("\n%s~~ Monstres%s\n",TC_CYN, RESET);
            int life;
            for (int i = 0; i < monsters->numberOfMonster; i++) {
                life = getPercentage(monsters->monsters[i].life, monsters->monsters[i].total_life);
                printf("%s%s%s%s (Vie: %d)\n", TC_BG_WHT,BLACK, monsters->monsters[i].name,RESET,monsters->monsters[i].life);
                update_bar(life,"",GREEN);
                makeSpace(2);
            }
            sleep_(50);
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

void displayGameOver(){
    printf("\n");

    printf(RED);
    printf(" _______  _______  __   __  _______    _______  __   __  _______  ______\n");
    printf("|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |   \n");
    printf("|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||   \n");
    printf("|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_  \n");
    printf("|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  | \n");
    printf(RESET);
    printf("|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | | \n");
    printf("|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_| \n");
    printf("\n");
}

void displayWin(){
    printf("\n");

    printf(GREEN);
    printf(" __   __  _______  __   __    _     _  ___   __    _ \n");
    printf("|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |\n");
    printf("|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |\n");
    printf("|       ||  | |  ||  |_|  |  |       ||   | |       |\n");
    printf("|_     _||  |_|  ||       |  |       ||   | |  _    |\n");
    printf(RESET);
    printf("  |   |  |       ||       |  |   _   ||   | | | |   |\n");
    printf("  |___|  |_______||_______|  |__| |__||___| |_|  |__|\n");
    printf("\n");
}

void displayAppearanceMessage(Monsters *monsters, int state){
    if (state == 0) {
        if (monsters->numberOfMonster > 1)
            printf("\n\t %s Des monstres apparaissent !%s\n\n", TC_YEL, RESET);
        else
            printf("\n\t %s Un monstre apparait !%s\n\n", TC_YEL, RESET);
    } else {
        printf("\n\t %s La partie continue ! %s\n\n", TC_YEL, RESET);
    }
}

void displayPlayerPreviousData(Player *player){
    printf("Bienvenue parmi nous, votre inventaire durant votre partie precedente s'affiche juste en bas\n");
    printf("\n+++++++++++++++++++++\n");
    displayInventory(player);
    printf("\n+++++++++++++++++++++\n");
}


void play(Monsters *monsters, Player *player, Carte *carte){
    int clean = 0;
    while(1) {
        displayAppearanceMessage(monsters,clean);
        afficherCarte(carte);
        int isPlayerWin = playerTour(monsters, player, clean);

        if (isPlayerWin) {
            displayWin();
            freeMonsters(monsters->monsters);

            printf("Voulez-vous continuer et sauvegarder plus tard ? (o/n)\n");
            int isContinue = handleYesOrNo(">> ");

            if (isContinue) {
                int difficulty = monsters->monsterDifficulty + 1;
                *monsters = regenerateMonsters(difficulty);
                monsters->monsterDifficulty = difficulty;
                changerDeZone(carte,player);
            } else {
                printf("sauvegarder maintenant (o/n) q pour quitter\n");
                int isSave = handleYesOrNo(">> ");

                if (isSave == 1) {
                    saveGame(player);
                    printf("Voulez-vous continuer ?(o/n)\n");
                    isContinue = handleYesOrNo(">> ");
                    if (isContinue){
                        int difficulty = monsters->monsterDifficulty + 1;
                        *monsters = regenerateMonsters(difficulty);
                        monsters->monsterDifficulty = difficulty;
                        changerDeZone(carte,player);
                    } else {
                        printf("bye !");
                        exit(0);
                    }
                } else if(isSave == 0){
                    int difficulty = monsters->monsterDifficulty + 1;
                    *monsters = regenerateMonsters(difficulty);
                    monsters->monsterDifficulty = difficulty;
                    changerDeZone(carte, player);
                }
                else {
                    printf("bye !");
                    exit(0);
                }
            }
        } else {
            clean = 1;
            int isPlayerDied = monstersTour(monsters, player);

            if (isPlayerDied) {
                clearConsole();
                displayGameOver();
                break;
            }
        }
        clean++;
    }
}