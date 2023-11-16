// Structure pour représenter un monstre
#ifndef CHARACTER_H
#define CHARACTER_H

#define MONSTERS "monsters/"
#define PLAYERS "players/"
#define DIRECTORY "../characters/"
#define SPACE_BETWEEN_MONSTERS 10
#define INITIAL_POSITION 5
#define INITIAL_MONSTER_X 80


typedef struct {
    int x;
    int y;
    char **skin;
}BaseCharacter;

typedef struct
{
    BaseCharacter base;
    char *name;
    int total_life;
    int life;
    int min_attack;
    int max_attack;
    int defense;
    int gold_reward;
} Monster;

typedef struct
{
    Monster *monsters;
    int numberOfMonster;
    int monsterDifficulty;
}Monsters;

// Structure pour représenter un objet
typedef struct
{
    int type;
    int value;
} Item;

// Structure pour représenter une arme
typedef struct
{
    char name[20];
    int damage;
    int attacks_per_turn;
    int value;
}  Weapon;

// Structure pour représenter une armure
typedef struct
{
    char name[20];
    int defense;
    int value;
} Armor;

// Structure pour représenter un sort
typedef struct {
    char name[20];
    int mana_cost;
    int damage;
} Spell;

// Structure pour représenter un joueur
typedef struct
{
    BaseCharacter base;
    int total_life;
    int life;
    int attacks_per_turn;
    int damage;
    int defense;
    int gold;
    int mana;
    int inventory_size;
    int equipped_weapon;
    int equipped_armor;
    Weapon weapon;
    Armor armor;
} Player;

typedef struct{
    Weapon *weapons; // magasin d'armes
    Armor *armors; // magasin d'armures
}Store;


Monster generateMonster(int difficulty,unsigned int seed);
void displayAllMonstersSkin(Monsters *monsters);
Player initializePlayer();
void setCharacterPosition(BaseCharacter *base, int positionX, int positionY);
void freeMonsters(Monster *monsterArray);
Monsters regenerateMonsters(int difficulty);
void displayPlayer(Player *player);
void displayMonster(Monster *monster);
int numberOfLineInMonsterAscii(const char *monster_name);
void displayMonsterSkinLine(const char *monster_name, int maxLineLength, int lineIndex);
void print_monsters(Monsters *monsters);
void display_monster(Monster *monster);
void displayMonsterLines(const char *monter_name);
void displayPlayerSkin(int life, int mana);
#endif // CHARACTER_H

