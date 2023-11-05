//
// Created by ayyub on 10/2.txt/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "character.h"
#include "../game/game.h"


char *names[] = {
        "ant",
        "snail",
        "snake",
        "minotaur",
        "demon",
        "skeleton",
        "ghost"};

char *hero[] = {
        "      _,.",
        "    ,` -.)",
        "   ( _/-\\-._",
        "  /,|`--._,-^|            " RED ", " RESET "",
        "  \\_| |`-._/||          " RED ",'| " RESET "",
        "    |  `-, / |         " RED "/  /," RESET "",
        "    |     || |        " RED "/  / ," RESET "",
        "     `r-._||/   __   /  /  " RED "," RESET "",
        " __,-<_     )`-/  `./  /   " RED "," RESET "",
        "'  \\   `---'   \\   /  /",
        "    |           |./  /",
        "    /           //  /",
        "\\_/' \\         |/  /",
        " |    |   _,^-'/  /",
        " |    , ``  (\\/  /_",
        "  \\,.->._    \\X-=/^",
        "  (  /   `-._//^`",
        "   `Y-.____(__}",
        "    |     {__}",
        "          ()"};

char *ant[] = {
        "              \\(" RED "\"" RESET ")/                ",
        "              -( )-                ",
        "              /(_)\\               "};

char *snail[] = {
        "" RED "@" RESET "             _________            ",
        " \\____       /         \\         ",
        " /    \\     /   ____    \\        ",
        " \\_    \\   /   /    \\    \\     ",
        "   \\    \\ (    \\__/  )    )     ",
        "    \\    \\_\\ \\______/    /     ",
        "     \\      \\           /___     ",
        "      \\______\\_________/____\\   "};

char *snake[] = {
        "                           (" RED "o" RESET ")(" RED "o" RESET ")  ",
        "                          /     \\ ",
        "                         /       | ",
        "                        /   \\  * |",
        "          ________     /    /\\__/ ",
        "  _      /        \\   /    /      ",
        " / \\    /  ____    \\_/    /      ",
        "//\\ \\  /  /    \\         /      ",
        "V  \\ \\/  /      \\       /       ",
        "    \\___/        \\_____/         "};

char *minotaur[] = {
        "       .      .                    ",
        "       |\\____/|                   ",
        "      (\\|----|/)                  ",
        "       \\ " RED "0" RESET "  " RED "0" RESET " /                    ",
        "        |    |                     ",
        "     ___/\\../\\____               ",
        "    /     --       \\              ",
        "   /  \\         /   \\            ",
        "  |    \\___/___/(   |             ",
        "  \\   /|  }{   | \\  )            ",
        "   \\  ||__}{__|  |  |             ",
        "    \\  |;;;;;;;\\  \\ / \\_______ ",
        "     \\ /;;;;;;;;| [,,[|======'    ",
        "       |;;;;;;/ |     /            ",
        "       ||;;|\\   |                 ",
        "       ||;;/|   /                  ",
        "       \\_|:||__|                  ",
        "        \\ ;||  /                  ",
        "        |= || =|                   ",
        "        |= /\\ =|                  ",
        "        /_/  \\_\\                 "};

char *demon[] = {
        "                    /\\            ",
        "                    ||             ",
        "      ____ " YELLOW "(((+)))" RESET " _||_            ",
        "     /.--.\\  .-.  /.||.\\         ",
        "    /.,   \\\\(" RED "0" RESET "." RED "0" RESET ")// || \\\\          ",
        "   /;`\";/\\ \\\\|m|//  ||  ;\\    ",
        "   |:   \\ \\__`:`____||__:|       ",
        "   |:    \\__ \\T/ (@~)(~@)|       ",
        "   |:    _/|     |\\_\\/  :|       ",
        "   |:   /  |     |  \\   :|        ",
        "   |'  /   |     |   \\  '|        ",
        "    \\_/    |     |    \\_/        ",
        "           |     |                 ",
        "           |_____|                 ",
        "           |_____|                 "};

char *skeleton[] = {
        "              .-.                  ",
        "             (" RED "o" RESET "." RED "o" RESET ")                 ",
        "              |=|                  ",
        "             __|__                 ",
        "           //.=|=.\\\\             ",
        "          // .=|=. \\\\            ",
        "          \\\\ .=|=. //            ",
        "           \\\\(_=_)//             ",
        "            (:| |:)                ",
        "             || ||                 ",
        "             () ()                 ",
        "             || ||                 ",
        "             || ||                 ",
        "            ==' '==                "};

char *ghost[] = {
        "           .-.                     ",
        "          (" RED "o" RESET " " RED "o" RESET ") boo!               ",
        "          | O \\                   ",
        "           \\   \\                 ",
        "            `~~~'                  "};

char *boss[] = {
        "                              _.--\"\"-._  ",
        "  .                         .\"         \".",
        " / \\    ,^.         /(     Y             |      )\\",
        "/   `---. |--'\\    (  \\__..'--   -   -- -'\"\"-.-'  )",
        "|        :|    `>   '.     l_..-------.._l      .'",
        "|      __l;__ .'      \"-.__.||_.-'v'-._||`\"----\"",
        " \\  .-' | |  `              l._       _.'",
        "  \\/    | |                   l`^^'^^'j",
        "        | |                _   \\_____/     _",
        "        j |               l `--__)-'(__.--' |",
        "        | |               | /`---``-----'\"1 |  ,-----.",
        "        | |               )/  `--' '---'   \\'-'  ___  `-.",
        "        | |              //  `-'  '`----'  /  ,-'   I`.  \\",
        "      _ L |_            //  `-.-.'`-----' /  /  |   |  `. \\",
        "     '._' / \\         _/(   `/   )- ---' ;  /__.J   L.__.\\ :",
        "      `._;/7(-.......'  /        ) (     |  |            | |",
        "      `._;l _'--------_/        )-'/     :  |___.    _._./ ;",
        "        | |                 .__ )-'\\  __  \\  \\  I   1   / /",
        "        `-'                /   `-\\-(-'   \\ \\  `.|   | ,' /",
        "                           \\__  `-'    __/  `-. `---'',-'",
        "                              )-._.-- (        `-----'",
        "                             )(  l\\ o ('..-.",
        "                       _..--' _'-' '--'.-. |",
        "                __,,-'' _,,-''            \\ \\",
        "               f'. _,,-'                   \\ \\",
        "              ()--  |                       \\ \\",
        "                \\.  |                       /  \\",
        "                  \\ \\                      |._  |",
        "                   \\ \\                     |  ()|",
        "                    \\ \\                     \\  /",
        "                     ) `-.                   | |",
        "                    // .__)                  | |",
        "                 _.//7'                      | |",
        "               '---'                         j_| ` ",
        "                                            (| |",
        "                                             |  \\",
        "                                             |lllj",
        "                                             ||||| "};



Monsters getMonsters(int difficulty){
    Monsters monsters;
    srand(time(NULL));
    int numMonsters = rand() % MAX_MONSTERS + 1;
    int placeMonster = 0;
    Monster *monsterArray = malloc(numMonsters * sizeof(Monster));
    for (int i = 0; i < numMonsters; i++)
    {
        // Generate a unique seed for each monster
        unsigned int seed = (unsigned int)time(NULL) + i;
        monsterArray[i] = generateMonster(difficulty,seed);
        if (i == 0)
            placeMonster = INITIAL_POSITION+1;
        else
            placeMonster += SPACE_BETWEEN_MONSTERS;
        setCharacterPosition(&monsterArray[i].base, INITIAL_MONSTER_X, placeMonster);
    }
    monsters.monsters = monsterArray;
    monsters.numberOfMonster = numMonsters;
    return monsters;
}

void displayAllMonsters(Monsters *monsters){
    // Determine the maximum line length
    int maxLineLength = actualStringLength(snake[0]);

    // Find the monster with the maximum number of lines
    int maxNumLines = 0;
    for (int i = 0; i < monsters->numberOfMonster; i++)
    {
        Monster monster = monsters->monsters[i];

        // Determine the number of lines in this monster's ASCII art
        int numLines = numberOfLineInMonsterAscii(monster.name);


        // Update the maximum number of lines
        if (numLines > maxNumLines)
            maxNumLines = numLines;
    }

    // Display all monsters on the same line
    for (int i = 0; i < maxNumLines; i++)
    {
        for (int j = 0; j < monsters->numberOfMonster; j++)
        {
            Monster monster = monsters->monsters[j];

            // Determine the number of lines in this monster's ASCII art
             int numLines = numberOfLineInMonsterAscii(monster.name);

            // Display monster line (or spaces if not available)
            if (i < numLines)
                displayMonsterSkinLine(monster.name,maxLineLength,i);
            else
                printf("%-*s", maxLineLength, "");

            // Display a space between monsters
            if (j < monsters->numberOfMonster -1)
                printf("  ");

        }
        printf("\n");
    }
}

void freeMonsters(Monsters *monsters){
    for (int i=0; i<monsters->numberOfMonster; i++){
        free(monsters->monsters[i].name);
    }
    free(monsters->monsters);
    free(monsters);

}

int numberOfLineInMonsterAscii(const char *monster_name){
    int numLines = 0;
    if (strcmp(monster_name, "ant") == 0)
        numLines = LEN(ant);
    else if (strcmp(monster_name, "snail") == 0)
        numLines = LEN(snail);
    else if (strcmp(monster_name, "snake") == 0)
        numLines = LEN(snake);
    else if (strcmp(monster_name, "minotaur") == 0)
        numLines = LEN(minotaur);
    else if (strcmp(monster_name, "demon") == 0)
        numLines = LEN(demon);
    else if (strcmp(monster_name, "skeleton") == 0)
        numLines = LEN(skeleton);
    else if (strcmp(monster_name, "ghost") == 0)
        numLines = LEN(ghost);
    return numLines;
}

Monster generateMonster(int difficulty,unsigned int seed)
{
    int BASE_STAT;
    switch(difficulty){
        case 1:
            BASE_STAT = 15;
            break;
        case 2:
            BASE_STAT = 30;
            break;
        case 3:
            BASE_STAT = 45;
            break;
        case 4:
            BASE_STAT = 60;
            break;
        case 5:
            BASE_STAT = 75;
            break;
        default:
            BASE_STAT = 15;
            break;
    }

    Monster monster;
    srand(seed);
    int randomIndex = rand() % LEN(names);
    char *name = names[randomIndex];
    monster.name = name;
    monster.life = rand() % (BASE_STAT +1) + 1 ;
    monster.min_attack = rand() % (BASE_STAT/10) + 1 ;
    monster.max_attack = rand() % (BASE_STAT/5) + 1;
    monster.defense = rand() % (BASE_STAT/10) + 1;
    monster.gold_reward = rand() % (BASE_STAT/5) + 1;
    return monster;
}


void displayMonsterSkinLine(const char *monster_name, int maxLineLength, int lineIndex)
{

    if (strcmp(monster_name, "ant") == 0)
        printf("%-*s", maxLineLength, ant[lineIndex]);
    else if (strcmp(monster_name, "snail") == 0)
        printf("%-*s", maxLineLength, snail[lineIndex]);
    else if (strcmp(monster_name, "snake") == 0)
        printf("%-*s", maxLineLength, snake[lineIndex]);
    else if (strcmp(monster_name, "minotaur") == 0)
        printf("%-*s", maxLineLength, minotaur[lineIndex]);
    else if (strcmp(monster_name, "demon") == 0)
        printf("%-*s", maxLineLength, demon[lineIndex]);
    else if (strcmp(monster_name, "skeleton") == 0)
        printf("%-*s", maxLineLength, skeleton[lineIndex]);
    else if (strcmp(monster_name, "ghost") == 0)
        printf("%-*s", maxLineLength, ghost[lineIndex]);
}

Player initializePlayer()
{
    Player player;
    player.base.x = INITIAL_POSITION;
    player.base.y = INITIAL_POSITION;
    player.life = 100;
    player.attacks_per_turn = 1;
    player.damage = 20;
    player.defense = 10;
    player.inventory_size = 10;
    player.equipped_weapon = -1; // Aucune arme équipée
    player.equipped_armor = -1;  // Aucune armure équipée
    player.gold = 0;
    return player;
}

void display_hero()
{
    // Print the hero
    int numLines1 = LEN(hero);
    int maxLineLength = 0;
    for (int i = 0; i < numLines1; i++)
    {
        int lineLength = actualStringLength(hero[i]);
        if (lineLength > maxLineLength)
            maxLineLength = lineLength;

    }
    for (int i = 0; i < numLines1; i++)
    {
        printf("%-*s", maxLineLength, hero[i]);
        printf("\n");
    }
}


void displayPlayer(Player *player)
{
    printf("x position : %d\n", player->base.x);
    printf("y position : %d\n", player->base.y);
    printf("Life : %d\n", player->life);
    printf("Damage : %d\n", player->damage);
    printf("Defense : %d\n", player->defense);
    printf("gold : %d\n", player->gold);
    printf("Equipped weapon : %d\n", player->equipped_weapon);
    printf("Equipped armor : %d\n", player->equipped_armor);
}

void displayMonster(Monster *monster)
{
    printf("Name : %s\n", monster->name);
    printf("x position : %d\n", monster->base.x);
    printf("y position : %d\n", monster->base.y);
    printf("Life : %d\n", monster->life);
    printf("Min damage : %d\n", monster->min_attack);
    printf("Max damage: %d\n", monster->max_attack);
    printf("Defense : %d\n", monster->defense);
    printf("gold : %d\n", monster->gold_reward);
}

void setCharacterPosition(BaseCharacter *base, int positionX, int positionY){
    base->x = positionX;
    base->y = positionY;
}

void print_monsters(Monsters *monsters)
{
    for (int i = 0; i < monsters->numberOfMonster; i++)
    {
        display_monster(&monsters->monsters[i]);
    }
}

void display_monster(Monster *monster)
{
    // Display the monster's ASCII art based on its name
    displayMonsterLines(monster->name);
    printf("------- INFO ----------\n");
    displayMonster(monster);
}

void displayMonsterLines(const char *monter_name)
{
    if (strcmp(monter_name, "ant") == 0)
        for (int i = 0; i < LEN(ant); i++)
            printf("%s\n", ant[i]);
    else if (strcmp(monter_name, "snail") == 0)
        for (int i = 0; i < LEN(snail); i++)
            printf("%s\n", snail[i]);
    else if (strcmp(monter_name, "snake") == 0)
        for (int i = 0; i < LEN(snake); i++)
            printf("%s\n", snake[i]);
    else if (strcmp(monter_name, "minotaur") == 0)
        for (int i = 0; i < LEN(minotaur); i++)
            printf("%s\n", minotaur[i]);
    else if (strcmp(monter_name, "demon") == 0)
        for (int i = 0; i < LEN(demon); i++)
            printf("%s\n", demon[i]);
    else if (strcmp(monter_name, "boss") == 0)
        for (int i = 0; i < LEN(boss); i++)
            printf("%s\n", boss[i]);
    else if (strcmp(monter_name, "skeleton") == 0)
        for (int i = 0; i < LEN(skeleton); i++)
            printf("%s\n", skeleton[i]);
    else if (strcmp(monter_name, "ghost") == 0)
        for (int i = 0; i < LEN(ghost); i++)
            printf("%s\n", ghost[i]);
}