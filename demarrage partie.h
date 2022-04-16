#ifndef PROJET_BOGGLE_DEMARRAGE_PARTIE_H
#define PROJET_BOGGLE_DEMARRAGE_PARTIE_H

#endif //PROJET_BOGGLE_DEMARRAGE_PARTIE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int Dimension_grille();
char Generation_lettre_aleatoire();
void Generation_sous_carre3x3(char sous_carre3x3[9]);
void Generation_grille(char grille[8][8], short longueur);