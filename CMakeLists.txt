cmake_minimum_required(VERSION 3.26)
project(DoomdepthC C)

set(CMAKE_C_STANDARD 11)

add_executable(DoomdepthC main.c characters/character.c fights/fights.c items/items.c save/save.c map/map.c game/game.c
        console/console.c
        console/console.h)
