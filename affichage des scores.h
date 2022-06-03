#ifndef MAIN_C_AFFICHAGE_DES_SCORES_H
#define MAIN_C_AFFICHAGE_DES_SCORES_H

#endif //MAIN_C_AFFICHAGE_DES_SCORES_H

/**
 * Fonction demandant à l'utilisateur la taille de la grille pour afficher les scores associés à cette grille
 * @return atoi(&dimension[0])
 */
int Dimension_grille_score();

/**
 * Fonction affichant les scores réalisés selon une certaine dimension de grille
 * @param dimension_grille
 * @param longueur_fichier
 */
void Affichage_par_grille(short dimension_grille, short longueur_fichier);

/**
 * Fonction affichant les scores d'un utilisateur en particulier
 * @param longueur_fichier
 */
void Affichage_par_pseudo(short longueur_fichier);