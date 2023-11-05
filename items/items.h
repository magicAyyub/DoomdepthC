//
// Created by ayyub on 10/22/2023.
//
#ifndef ITEMS_H
#define ITEMS_H
#include "../characters/character.h"


Weapon generateWeapon();
Armor generateArmor();
void equipItem(Player *player, Item *item);
void unequipItem(Player *player, Item *item);
void displayInventory(Player player);
#endif // ITEMS_H