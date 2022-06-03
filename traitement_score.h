#ifndef MAIN_C_ENREGISTREMENT_SCORE_H
#define MAIN_C_ENREGISTREMENT_SCORE_H

#endif //MAIN_C_ENREGISTREMENT_SCORE_H

/**
 * Fonction supprimant la ligne de fin de fichier afin d'incrémenter correctement le score de l'utilisateur
 */
void Suppression_fin_fichier();

/**
 * Fonction permettant d'enregistrer le score de l'utilsateur à la fin du fichier score
 * @param score
 * @param longueur
 */
void Enregistrement_score(float score, short longueur, short temps);

/**
 * Fonction permettant de compter le nombre de lignes dans le fichier score
 * @return nombre_de_lignes
 */
int Nombre_de_lignes();

/**
 * Fonction réalisant le tri des scores décroissant lors de l'ajout d'un nouveau score
 */
void Tri_score();