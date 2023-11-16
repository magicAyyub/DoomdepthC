//
// Created by ayyub on 10/22/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "map.h"

Carte initialiseCarte(){
    Carte carte;
    carte.zone = 1;
    carte.niveauDifficulte = 1;
    return carte;
}

// affichage de la carte
void afficherCarte(Carte *carte) {

    switch (carte->zone) {
        case 1:
            printf("\n\t%s Vous etes sur la zone %s %s\n",TC_YEL, RESET, ZONE1);
            break;
        case 2:
            printf("\n\t%s Vous etes sur la zone %s %s\n", TC_YEL,RESET, ZONE2);
            break;
        case 3:
            printf("\n\t%s Vous etes sur la zone %s %s\n", TC_YEL, RESET, ZONE3);
            break;
        case 4:
            printf("\n\t%s Vous etes sur la zone %s %s\n", TC_YEL, RESET, ZONE4);
            break;
        case 5:
            printf("\n\t%s Vous etes sur la zone %s %s\n", TC_YEL, RESET, ZONE5);
            break;
        case 6:
            printf("\n\t%s Vous etes sur la zone %s %s\n", TC_YEL, RESET, ZONE6);
            break;
        case 7:
            printf("\n\t%s Vous etes sur la zone %s %s\n", TC_YEL, RESET, ZONE7);
            break;
        case 8:
            printf("\n\t%s Vous etes sur la zone %s %s\n", TC_YEL, RESET, ZONE8);
            break;
        default:
            printf("\n\t%s Vous etes sur une zone d'elite%s",TC_YEL, RESET);
            break;
    }
}

void changerDeZone(Carte *carte, Player *player, Store *store) {
    if (carte->zone < 8) {
        carte->zone++;
        printf("\t\n%sBien joue ! Vous avez atteint la zone %d%s : ",TC_YEL, carte->zone, RESET);
    }else{
        printf("\t\n%sFélicitations ! Vous etes arrive dans la cour des grands.%s\n",TC_YEL, RESET);
    }

    printf("\n Desirez-vous faire autre chose avant la prochaine zone ? \n\n1. Consulter l'inventaire\n 2. acheter des equipements\n 3. Continuer la partie\n\n");
    short choice = handleChoice(">> ",1,3);

    switch (choice) {
        case 1:
            sleep_(100);
            printf("\n++++++++++++++++++++++++++\n");
            displayInventory(player);
            printf("++++++++++++++++++++++++++\n\n");
            break;
        case 2:
            sleep_(100);
            displayStoreMenu();
            short item = handleChoice(" ",1,3);
            if (item != 3)
                buyItem(player,store,item);
            else
                printf("compris");
            break;
        case 3:
            break;
    }

    printf("Continuer la partie (o/n)");
    int isContinue = handleYesOrNo(">> ");
    if (isContinue == 0){
        printf("bye !");
        exit(0);
    }
}


void cartography(Carte *carte) {
    printf("Cartographie :\n");

    for (int i = 1; i <= 8; i++) {
        printf("%d. ", i);

        // Afficher une croix à côté des zones gagnées
        if (i <= carte->zone) {
            printf("[X] ");
        } else {
            printf("[ ] ");
        }

        // Afficher le nom de la zone
        switch (i) {
            case 1:
                printf("%s\n", ZONE1);
                break;
            case 2:
                printf("%s\n", ZONE2);
                break;
            case 3:
                printf("%s\n", ZONE3);
                break;
            case 4:
                printf("%s\n", ZONE4);
                break;
            case 5:
                printf("%s\n", ZONE5);
                break;
            case 6:
                printf("%s\n", ZONE6);
                break;
            case 7:
                printf("%s\n", ZONE7);
                break;
            case 8:
                printf("%s\n", ZONE8);
                break;
            default:
                printf("%s\n","Zone Elite");
                break;
        }
    }
    printf("\n");
}
