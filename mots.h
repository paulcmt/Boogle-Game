#ifndef MAIN_C_MOTS_H
#define MAIN_C_MOTS_H

#endif //MAIN_C_MOTS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int Nombre_de_lettres_connues(char grille[8][8], char lettre_a_compter, int longueur);
void Coordonnes_lettre(char lettre, int longueur, char grille[8][8], int *L, int *C);
void Obtention_lettres_autour(char lettre_autour[], char lettre, char grille[8][8], int longueur);
void Traitement_mot(char tabmots[], char grille[8][8], int longueur);
void Saisie_de_mots(int temps_limite, char grille[8][8], int longueur);