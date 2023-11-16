//
// Created by ayyub on 10/22/2023.
//
#ifndef ITEMS_H
#define ITEMS_H
#include "../characters/character.h"
#define numberOfItems  4


Store initializeStore();
Weapon generateWeapon();
Armor generateArmor();
void equipItem(Player *player, Item *item);
void unequipItem(Player *player, Item *item);
void displayInventory(Player *player);
void displayStoreMenu();
void buyItem(Player *player, Store *store, int choice);
void freeStore(Store *store);
#endif // ITEMS_H