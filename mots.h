#ifndef MAIN_C_MOTS_H
#define MAIN_C_MOTS_H

#endif //MAIN_C_MOTS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int Nb_de_lettres_grille(char grille[8][8], char lettre_a_compter, int longueur);
void Coordonnees_lettre(char lettre, int longueur, char grille[8][8], int *indiceL, int *indiceC);
void Obtention_lettres_autour(char lettre_autour[8], int indiceC, int indiceL, char grille[8][8], int longueur);
int Position_lettre_tab_lettre_autour(char lettre_autour[8], char lettre, int longueur);
void Traitement_mot(char tabmots[], char grille[8][8], int longueur);
void Saisie_de_mots(int temps_limite, char grille[8][8], int longueur);