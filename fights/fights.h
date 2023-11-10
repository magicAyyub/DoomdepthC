//
// Created by ayyub on 10/22/2023.
//
#ifndef FIGHTS_H
#define FIGHTS_H
#include "../characters/character.h"
#include "../console/console.h"

#define MAX_PERCENT 100
#define PROGRESS_BAR_WIDTH 50

void attackOnPlayer(Monsters monster, Player *player);
void attackOnMonster(Player *player,Monsters *monsters);
void hurtMonster(Monster *monster, int damage);
Spell generateSpell();
void castSpell(Player *player, Spell spell);
void regenerateMana(Player *player);
void update_bar(int percent_done, const char *msg, const char *color);
void display_bar();
int getPercentage(int current, int total);

#endif