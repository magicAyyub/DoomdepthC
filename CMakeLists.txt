cmake_minimum_required(VERSION 3.26)
project(DoomdepthC C)

set(CMAKE_C_STANDARD 11)

add_executable(DoomdepthC main.c
        characters/character.c)
