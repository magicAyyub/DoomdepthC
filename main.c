#include<stdio.h>

#include "console/console.h"
#include "game/game.h"

int main() {
    displayHomeBanner();
    short choice;
    //Menu
    printf("\n 1. Start Game\n 2. Load\n 3. Quit\n\n");
    printf("Enter your choice: ");
    while (1) {
        scanf("%hd", &choice);
        clear_stdin();
        if (choice == 1) {
            clear_screen();
            Monsters monsters = getMonsters(2);
            displayAllMonsters(&monsters);
            printf("\n\n\n\n\n");

            display_hero();

        } else if (choice == 2){
            //
        } else if (choice == 3){
            printf("See you soon !");
            break;
        }
        else {
            printf("Invalid choice, please enter valid choice : ");
            continue;
        }
    }
    return 0;
}






