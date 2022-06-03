#ifndef PROJET_BOGGLE_FONCTIONS_GLOBALES_H
#define PROJET_BOGGLE_FONCTIONS_GLOBALES_H

#endif //PROJET_BOGGLE_FONCTIONS_GLOBALES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

/**
 * Fonction comptant le nombre de lettre dans un tableau de lettres
 * @param Tabl
 * @param lettre
 * @return compteur
 */
int Comptage_lettre_tableau(char Tabl[], char lettre);

/**
 * Fonction intialisant un tableau de lettre
 * @param tabl
 */
void Initialisation_tableau(char tabl[]);

/**
 * Fonction affichant la grille selon une dimension
 * @param grille
 * @param longueur
 */
void Affichage_grille(char grille[8][8], int longueur); // Permet d'afficher la grille depuis n'importe quel fichier