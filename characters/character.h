//
// Created by ayyub on 10/2.txt/2023.
//
typedef struct {
    int x;
    int y;
    char *asciiArt;
}BaseCharacter;

typedef struct{
    int id;
    char *name;
    char *description;
    int price;
    int attack_power;
    int required_level;
    int movement_speed;
    int hit_number;
}Weapon;

typedef struct{
    int id;
    char *name;
    char *description;
    int price;
    int protection;
}Armor;

typedef struct{
    BaseCharacter base;
    int health;
    int attack;
    int defense;
    int speed;
}Monster;

typedef struct{
    BaseCharacter base;
    int health;
    int attack;
    int defense;
    int speed;
    int level;
    Weapon weapon;
    Armor armor;
}Player;



Monster *createMonster(int monsterId);
Player *createPlayer(int playerId);
void initPlayerStats(Player *player);
void generateRandomMonsterStats(Monster *monster);
void readAsciiArtFromFile(const char *asciiFileName, BaseCharacter *baseOfCharacter);
void freeAsciiArt(BaseCharacter *baseOfCharacter);
void freeMonster(Monster *monster);
void freePlayer(Player *player);