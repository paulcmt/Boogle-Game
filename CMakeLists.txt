cmake_minimum_required(VERSION 3.21)
project(Projet_Boggle C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_Boggle main.c menu.c menu.h "generation grille.c" "generation grille.h" "fonctions globales.c" "fonctions globales.h" "mots.c" "score.c" "score.h" mots.h)
