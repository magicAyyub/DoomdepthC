//
// Created by ayyub on 10/22/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fights.h"
#include "../game/game.h"

int attackOnPlayer(Monsters *monsters, Player *player)
{
    for (int i = 0; i < monsters->numberOfMonster; i++)
    {
        int damage = (rand() % (monsters->monsters[i].max_attack - monsters->monsters[i].min_attack + 1)) + monsters->monsters[i].min_attack;

        hurtPlayer(monsters->monsters[i].name,player, damage);

        int life = getPercentage(player->life,player->total_life);
        int mana = getPercentage(player->mana,10);

        if (player->life <= 0)
        {
            return 1;
        }
        displayPlayerSkin(life, mana);
    }
    return 0;
}

void attackOnMonster(Player *player,Monsters *monsters) {
    int monsterNum = monsters->numberOfMonster - 1;

    if (monsterNum >= 1) {
        printf("--> Choisissez un monstre a attaquer entre %s0%s et %s%d%s:\n",TC_CYN,TC_WHT,TC_CYN, monsters->numberOfMonster - 1,RESET);
        makeSpace(1);
        for (int i = 0; i < monsters->numberOfMonster; i++) {
            printf(" %d. %s%s%s%s\n", i,TC_BG_WHT,BLACK, monsters->monsters[i].name,RESET);
            makeSpace(1);
        }
        short choice = handleChoice(">> ", 0, monsters->numberOfMonster - 1);

        int damage = player->damage - monsters->monsters[choice].defense;
        if (damage < 0)
            damage = 0;

        hurtMonster(&monsters->monsters[choice], damage);

        if (monsters->monsters[choice].life <= 0) {
            printf("\n %sLe monstre %s%s%s est mort!%s\n", TC_YEL, RESET,monsters->monsters[choice].name, TC_YEL, RESET);
            rewardPlayer(player, monsters->monsters[choice].gold_reward);
            readjustMonsters(monsters,choice);
        }
    } else {
        makeSpace(1);
        int damage = player->damage - monsters->monsters[0].defense;
        if (damage < 0)
            damage = 0;

        hurtMonster(&monsters->monsters[0], damage);

        if (monsters->monsters[0].life <= 0) {
            printf("\n %sLe monstre %s%s%s est mort!%s\n", TC_YEL,RESET, monsters->monsters[0].name,TC_YEL,RESET);
            rewardPlayer(player, monsters->monsters[0].gold_reward);
            readjustMonsters(monsters,0);
        }
    }
}

void hurtPlayer(const char *monster_name, Player *player, int damage){
    player->life -= damage;
    sleep_(800);
    printf("\n%s~~Le monstre %s%s%s vous inflige %s%d degats%s.%s\n",TC_YEL, RESET, monster_name,RESET, TC_CYN, damage, TC_YEL,RESET);
}

void hurtMonster(Monster *monster, int damage){
    monster->life -= damage;
    sleep_(800);
    printf("%s-->%s Vous infligez %s%d degat %s%sa %s%s!\n", RED, RESET, TC_CYN,damage,TC_WHT, RESET,monster->name,RESET);
}

void rewardPlayer(Player *player, int gold){
    player->gold += gold;
    printf("\n %s~~ Vous gagnez %d piece d'or%s\n", TC_MAG, gold,RESET);
}

Spell generateSpell() {
    Spell spell;
    char* spell_names[] = {"Éclair", "Guérison", "Bouclier", "Feu sacré"};
    strcpy(spell.name, spell_names[rand() % 4]);
    spell.mana_cost = rand() % 21 + 10; // Coût en mana aléatoire entre 10 et 30
    spell.damage = rand() % 41 + 20;    // Dégâts aléatoires entre 20 et 60
    return spell;
}

void castSpell(Player *player, Spell spell) {
    if (player->mana >= spell.mana_cost) {
        player->mana -= spell.mana_cost;
        int damage = spell.damage;
        // Appliquer les dégâts au monstre ici
        printf("Le joueur lance le sort \"%s\" et inflige %d dégâts au monstre.\n", spell.name, damage);
    } else {
        printf("Le joueur n'a pas suffisamment de mana pour lancer ce sort.\n");
    }
}

void regenerateMana(Player *player) {
    player->mana += 10; // Restauration de 10 points de mana par tour
    if (player->mana > 10) {
        player->mana = 10; // Limite la mana à 100
    }
}
void display_bar(){
    printf("[");
    for (int i = 0; i < PROGRESS_BAR_WIDTH; i++){
        printf("#");
    }
    printf("] 100%%");
}
void update_bar(int percent_done, const char *msg, const char *color){
    int num_chars = percent_done * PROGRESS_BAR_WIDTH / 100;
    printf("\r%s : ",msg);
    printf("%s",color);
    for (int i = 0; i < num_chars; i++){
        printf("#");
    }
    printf(RESET);
    for (int i = 0; i < PROGRESS_BAR_WIDTH-num_chars; i++){
        printf(RED);
        printf("-");
        sleep_(30);
    }
    printf(RESET);
    printf(" %d%%", percent_done);
    fflush(stdout);
}

int getPercentage(int current, int total){
    int percentage = (int)(((float)current/(float)total)*100);
    return percentage;
}

