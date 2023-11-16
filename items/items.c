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
    weapon.attacks_per_turn = rand() % 3 + 1; // Nombre d'attaques par tour entre 1
    return weapon;
}

Armor generateArmor()
{
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

void displayStoreMenu()
{
    printf("\n+++++++++++Magasin+++++++++\n");
    printf("1. Acheter une arme\n");
    printf("2. Acheter une armure\n");
    printf("4. Quitter le magasin\n");
    printf("+++++++++++++++++++++++++++\n");
    printf("Votre choix : ");

}

void buyItem(Player *player, Store *store, int choice)
{
    if (choice == 1) // Arme
    {
        if (player->gold >= store->weapons[choice].value)
        {
            player->gold -= store->weapons[choice].value;
            Item item;
            item.type = 0;
            item.value = store->weapons[choice].damage;
            equipItem(player, &item);
            printf("Vous avez achete %s pour %d pieces d'or\n", store->weapons[choice].name, store->weapons[choice].value);
        }
        else
        {
            printf("Vous n'avez pas assez d'or pour acheter cette arme\n");
        }
    }
    else if (choice == 2) // Armure
    {
        if (player->gold >= store->armors[choice].value)
        {
            player->gold -= store->armors[choice].value;
            Item item;
            item.type = 1;
            item.value = store->armors[choice].defense;
            equipItem(player, &item);
            printf("Vous avez achete %s pour %d pieces d'or\n", store->armors[choice].name, store->armors[choice].value);
        }
        else
        {
            printf("Vous n'avez pas assez d'or pour acheter cette armure\n");
        }
    }
    else
    {
        printf("Choix invalide\n");
    }
}

void showItems(Store *store)
{
    printf("Armes :\n");
    for (int i = 0; i < numberOfItems; i++)
    {
        printf("%d. %s (Dégâts : %d) (Prix : %d)\n", i + 1, store->weapons[i].name, store->weapons[i].damage, store->weapons[i].value);
    }

    printf("\nArmures :\n");
    for (int i = 0; i < numberOfItems; i++)
    {
        printf("%d. %s (Défense : %d) (Prix : %d)\n", i + 1, store->armors[i].name, store->armors[i].defense, store->armors[i].value);
    }

}

Store initializeStore(){
    Store store;

    store.weapons = malloc(sizeof(Weapon) * numberOfItems);
    store.armors = malloc(sizeof(Armor) * numberOfItems);

    store.weapons[0] = generateWeapon();
    store.weapons[1] = generateWeapon();
    store.weapons[2] = generateWeapon();
    store.weapons[3] = generateWeapon();
    store.armors[0] = generateArmor();
    store.armors[1] = generateArmor();
    store.armors[2] = generateArmor();
    store.armors[3] = generateArmor();
    return store;
}


void freeStore(Store *store){
    free(store->armors);
    free(store->weapons);
}


