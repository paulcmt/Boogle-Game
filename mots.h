#ifndef MAIN_C_MOTS_H
#define MAIN_C_MOTS_H

#endif //MAIN_C_MOTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Fonction retournant le nombre d'occurence de la première lettre du mot saisi dans la grille
 * @param grille
 * @param lettre_a_compter
 * @param longueur
 * @return compteur
 */
int Nb_de_lettres_grille(char grille[8][8], char lettre_a_compter, int longueur);

/**
 * Fonction donnant les coordonnées d'une lettre dans la grille à partir d'une certaine position
 * @param lettre
 * @param longueur
 * @param grille
 * @param indiceL
 * @param indiceC
 */
void Coordonnees_lettre(char lettre, int longueur, char grille[8][8], int *indiceL, int *indiceC);

/**
 * Fontion donnant les lettres autours d'une lettre à partir de ses coordonnées
 * @param lettre_autour
 * @param indiceC
 * @param indiceL
 * @param grille
 * @param longueur
 */
void Obtention_lettres_autour(char lettre_autour[8], int indiceC, int indiceL, char grille[8][8], int longueur);

/**
 * Fonction donnant la position d'une lettre dans un tableau de lettres autours
 * @param lettre_autour
 * @param lettre
 * @param longueur
 * @return i
 */
int Position_lettre_tab_lettre_autour(char lettre_autour[8], char lettre, int longueur);

/**
 * Fonction vérifiant l'existence du mot dans la grille (retourne 1 si oui et 0 sinon)
 * @param tabmots
 * @param grille
 * @param longueur
 * @return 0 ou 1
 */
int Verification_grille(char tabmots[], char grille[8][8], int longueur);

/**
 * Fonction vérifiant si le mot est présent dans la liste des mots français (retourne 1 si oui et 0 sinon)
 * @param mot_a_comparer
 * @return 0 ou 1
 */
int Verification_francais(char mot_a_comparer[]);

/**
 * Fonction donnant le nombre de mots valides saisi au cours de la partie
 * @param temps_limite
 * @param grille
 * @param longueur
 * @param tabmots
 * @return nb_de_mots_valide
 */
int Saisie_de_mots(int temps_limite, char grille[8][8], int longueur, char tabmots[][26]);