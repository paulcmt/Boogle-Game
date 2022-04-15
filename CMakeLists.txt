cmake_minimum_required(VERSION 3.21)
project(Projet_Boggle C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_Boggle main.c menu.c menu.h "demarrage partie.c" "demarrage partie.h" "fonctions globales.c" "fonctions globales.h")
