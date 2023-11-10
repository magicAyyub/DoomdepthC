//
// Created by ayyub on 10/22/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fights.h"
#include "../game/game.h"

void attackOnPlayer(Monsters monsters, Player *player)
{
    for (int i = 0; i < monsters.numberOfMonster; i++)
    {
        if (player->life <= 0)
        {
            printf("Le joueur a été vaincu. Fin du jeu.\n");
            exit(0);
        }

        int damage = (rand() % (monsters.monsters[i].max_attack - monsters.monsters[i].min_attack + 1)) + monsters.monsters[i].min_attack;
        player->life -= damage;
        printf("Le monstre %d inflige %d dégâts au joueur.\n", i + 1, damage);
    }
}

void attackOnMonster(Player *player,Monsters *monsters) {
    int monsterNum = monsters->numberOfMonster - 1;
    int life;

    if (monsterNum != 0) {
        printf("Choisissez un monstre a attaquer entre %s0%s et %s%d%s:\n",TC_CYN,TC_WHT,TC_CYN, monsters->numberOfMonster - 1,RESET);
        makeSpace(1);
        for (int i = 0; i < monsters->numberOfMonster; i++) {
            printf("%d pour %s%s%s%s (Vie: %d)\n", i,TC_BG_WHT,BLACK, monsters->monsters[i].name,RESET,monsters->monsters[i].life);
            life = getPercentage(monsters->monsters[i].life, monsters->monsters[i].total_life);
            update_bar(life,"",GREEN);
            makeSpace(2);
        }
        short choice = handleChoice(">> ", 0, monsters->numberOfMonster - 1);

        int damage = player->damage - monsters->monsters[choice].defense;
        if (damage < 0)
            damage = 0;

        hurtMonster(&monsters->monsters[choice], damage);
        printf("Vous infligez %s%d degat %s%sa %s%s!\n", TC_CYN,damage,TC_WHT, RESET,monsters->monsters[choice].name,RESET);

        if (monsters->monsters[choice].life <= 0) {
            printf("\n %sLe monstre %s%s%s est mort!%s\n", TC_YEL, RESET,monsters->monsters[choice].name, TC_YEL, RESET);
            readjustMonsters(monsters,choice);
        }
    } else {
        printf("%s%s%s\n", TC_BG_CYN, monsters->monsters[0].name,RESET);
        makeSpace(1);
        life = getPercentage(monsters->monsters[0].life, monsters->monsters[0].total_life);
        update_bar(life,"Vie",TC_CYN);
        makeSpace(2);
        int damage = player->damage - monsters->monsters[0].defense;
        if (damage < 0)
            damage = 0;

        hurtMonster(&monsters->monsters[0], damage);
        printf("Vous infligez %s%d degat %s%sa %s%s!\n", TC_CYN,damage,TC_WHT, RESET,monsters->monsters[0].name,RESET);
        if (monsters->monsters[0].life <= 0) {
            printf("\n %sLe monstre %s%s%s est mort!%s\n", TC_YEL,RESET, monsters->monsters[0].name,TC_YEL,RESET);
            readjustMonsters(monsters,0);
        }
    }
}

void hurtMonster(Monster *monster, int damage){
    monster->life -= damage;
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
    if (player->mana > 100) {
        player->mana = 100; // Limite la mana à 100
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
        printf("-");
    }
    printf(" %d%%", percent_done);
    fflush(stdout);
}

int getPercentage(int current, int total){
    return (current/total)*100;
}

