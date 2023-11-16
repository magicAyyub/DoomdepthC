//
// Created by ayyub on 10/22/2023.
//
#ifndef MAP_H
#define MAP_H
#include "../characters/character.h"
#include "../console/console.h"
#include "../items/items.h"

#define LARGEUR 50
#define HAUTEUR 50

// Définition des noms de zones
#define ZONE1 "Ile Paradis"
#define ZONE2 "Mur Maria"
#define ZONE3 "Mur Rose"
#define ZONE4 "Mur Sina"
#define ZONE5 "Java"
#define ZONE6 "Madagascar"
#define ZONE7 "Majorque"
#define ZONE8 "Sicile"
#define MAX_ZONES 10


// Structure carte
typedef struct {
    int zone;
    int niveauDifficulte;
} Carte;

Carte initialiseCarte();
void afficherCarte(Carte *carte) ;
void changerDeZone(Carte *carte, Player *player, Store *store);
void cartography(Carte *carte);

#endif
