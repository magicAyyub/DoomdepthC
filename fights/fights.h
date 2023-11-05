//
// Created by ayyub on 10/22/2023.
//
#ifndef FIGHTS_H
#define FIGHTS_H
#include "../characters/character.h"

#define MAX_PERCENT 100
#define PROGRESS_BAR_WIDTH 20

void attackOnPlayer(Monster monsters[], Player *player, int numMonsters);
void attackOnMonster(Player *player,Monster *monster);
Spell generateSpell();
void castSpell(Player *player, Spell spell);
void regenerateMana(Player *player);
void update_bar(int percent_done);
void display_bar();

#endif