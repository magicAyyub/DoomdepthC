//
// Created by ayyub on 10/22/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "items.h"

Weapon generateWeapon() {
    Weapon weapon;
    char* weapon_names[] = {"Épée en fer", "Hache de guerre", "Arc long", "Dague empoisonnée"};
    strcpy(weapon.name, weapon_names[rand() % 4]);
    weapon.attacks_per_turn = rand() % 3 + 1; // Nombre d'attaques par tour entre 1 et 3
    return weapon;
}

Armor generateArmor() {
    Armor armor;
    char* armor_names[] = {"Cotte de mailles", "Plastron en cuir", "Heaume de chevalier", "Tunique légère"};
    strcpy(armor.name, armor_names[rand() % 4]);
    armor.defense = rand() % 16 + 5;
    return armor;
}

void equipItem(Player *player, Item *item)
{
    if (item->type == 0) // Arme
    {
        Weapon weapon;
        char* weapon_names[] = {"Épée en fer", "Hache de guerre", "Arc long", "Dague empoisonnée"};
        strcpy(weapon.name, weapon_names[rand() % 4]);
        weapon.damage = item->value;
        player->damage = weapon.damage;
        player->equipped_weapon = 1;
        player->attacks_per_turn = weapon.attacks_per_turn;
        player->weapon = weapon;
    }

    else if (item->type == 1) // Armure
    {
        Armor armor;
        char* armor_names[] = {"Cotte de mailles", "Plastron en cuir", "Heaume de chevalier", "Tunique légère"};
        strcpy(armor.name, armor_names[rand() % 4]);
        armor.defense = item->value;
        player->defense = armor.defense;
        player->equipped_armor = 1;
        player->armor = armor;
    }

    else // Autre
    {
        player->gold += item->value;
    }
}

void unequipItem(Player *player, Item *item)
{
    if (item->type == 0) // Arme
    {
        player->damage -= item->value;
        player->equipped_weapon = -1;
    }
    else if (item->type == 1) // Armure
    {
        player->defense -= item->value;
        player->equipped_armor = -1;
    }
}

void displayInventory(Player *player)
{
    printf("Inventaire :\n");
    if (player->equipped_weapon >= 0)
        printf("> Arme equipee : %s (Dégâts : %d)\n", player->weapon.name, player->equipped_weapon);
    else
        printf("> Aucune arme equipee\n");

    if (player->equipped_armor >= 0)
        printf("> Armure equipee : %s (Défense : %d)\n", player->armor.name, player->equipped_armor);
    else
        printf("> Aucune armure portee\n");

    printf("> Or : %d\n", player->gold);

}


