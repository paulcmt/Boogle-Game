#ifndef PROJET_BOGGLE_DEMARRAGE_PARTIE_H
#define PROJET_BOGGLE_DEMARRAGE_PARTIE_H

#endif //PROJET_BOGGLE_DEMARRAGE_PARTIE_H

/**
 * Demande la dimension de la grille à l'utilisateur
 * @return atoi(&dimension)
 */
int Dimension_grille(); // Fonctionnel + commenté

/**
 * Génere la grille à partir de la dimension donnée précédemment
 * @param grille
 * @param longueur
 */
void Generation_grille(char grille[8][8], short longueur); // Fonctionnel + commenté

/**
 *
 * @return
 */
char Generation_lettre_aleatoire(); // Fonctionnel + commenté

/**
 *
 * @param sous_carre3x3
 */
void Generation_sous_carre3x3(char sous_carre3x3[9]); // Fonctionnel + commenté

/**
 *
 * @param sous_carre3x3
 */
void Lettre_commune_carre_3x3(char sous_carre3x3[9]); // Fonctionnel + commenté

/**
 *
 * @param grille
 * @param sous_carre3x3
 */
void Assignation_sous_carre_vers_grille(char grille[8][8], char sous_carre3x3[9]); // Fonctionnel + commenté

/**
 *
 * @param grille
 * @param sous_carre3x3
 * @param longueur
 */
void Generation_des_lettres_a_droite_premier(char grille[8][8], char sous_carre3x3[9], short longueur);

/**
 *
 * @param sous_carre3x3
 */
void Lettre_commune2(char sous_carre3x3[9]); // Fonctionnel + commenté

/**
 *
 * @param grille
 * @param longueur
 */
void Decalage_en_bas_et_vers_la_droite(char grille[8][8], short longueur); // Fonctionnel + commenté

/**
 *
 * @param sous_carre3x3
 */
void Lettre_commune3(char sous_carre3x3[9]); // Fonctionnel + commenté

/**
 *
 * @param sous_carre3x3
 */
void Lettre_commune4(char sous_carre3x3[9]); // Fonctionnel + commenté

void Lettre_commune5(char sous_carre3x3[9]);
