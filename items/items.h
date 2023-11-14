//
// Created by ayyub on 10/22/2023.
//
#ifndef ITEMS_H
#define ITEMS_H
#include "../characters/character.h"


// Structure pour représenter les pouvoirs magiques
 typedef struct{
    char symbole; // Symbole associé au pouvoir sur la carte
    int impact;   // Impact sur les points de vie des monstres
    int prix;     // Prix en pièces d'or
} Pouvoir;


Weapon generateWeapon();
Armor generateArmor();
void equipItem(Player *player, Item *item);
void unequipItem(Player *player, Item *item);
void displayInventory(Player *player);
#endif // ITEMS_H