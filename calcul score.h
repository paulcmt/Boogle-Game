#ifndef MAIN_C_CALCUL_SCORE_H
#define MAIN_C_CALCUL_SCORE_H

#endif //MAIN_C_CALCUL_SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 *
 * @param tabmots
 * @param temps_limite
 * @return score_total
 */
float Calcul_du_score(char tabmots[][26], short nb_de_mots_valides);

int Compteur_lettre(char tabmots[][26], short temps_limite, int i);