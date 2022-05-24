cmake_minimum_required(VERSION 3.21)
project(Projet_Boggle C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_Boggle main.c menu.c menu.h "generation grille.c" "generation grille.h" "fonctions globales.c" "fonctions globales.h" mots.c "menu score.c" "menu score.h" mots.h "calcul score.c" "calcul score.h" "enregistrement score.c" "enregistrement score.h")
