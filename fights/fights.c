//
// Created by ayyub on 10/22/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fights.h"

void attackOnPlayer(Monster monsters[], Player *player, int numMonsters)
{
    for (int i = 0; i < numMonsters; i++)
    {
        if (player->life <= 0)
        {
            printf("Le joueur a été vaincu. Fin du jeu.\n");
            exit(0);
        }

        int damage = (rand() % (monsters[i].max_attack - monsters[i].min_attack + 1)) + monsters[i].min_attack;
        player->life -= damage;
        printf("Le monstre %d inflige %d dégâts au joueur.\n", i + 1, damage);
    }
}

void attackOnMonster(Player *player,Monster *monster)
{
    int damage = player->damage - monster->defense;
    if (damage < 0)
    {
        damage = 0;
    }
    monster->life -= damage;
    printf("Le joueur inflige %d dégâts au monstre.\n", damage);
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
void update_bar(int percent_done){
    int num_chars = percent_done * PROGRESS_BAR_WIDTH / 100;
    printf("\r[");
    for (int i = 0; i < num_chars; i++){
        printf("#");
    }
    for (int i = 0; i < PROGRESS_BAR_WIDTH-num_chars; i++){
        printf("-");
    }
    printf("] %d%%", percent_done);
    fflush(stdout);
}