#ifndef MAIN_C_ENREGISTREMENT_SCORE_H
#define MAIN_C_ENREGISTREMENT_SCORE_H

#endif //MAIN_C_ENREGISTREMENT_SCORE_H

/**
 * Fonction permettant d'enregistrer le score de l'utilsateur à la fin du fichier score
 * @param score
 * @param longueur
 */
void Enregistrement_score(float score, short longueur);

/**
 * Fonction permettant de compter le nombre de lignes dans le fichier score
 * @return nombre_de_lignes
 */
int Nombre_de_lignes();

/**
 * Fonction réalisant le tri des scores lors de l'ajout d'un nouveau score
 */
void Tri_score();