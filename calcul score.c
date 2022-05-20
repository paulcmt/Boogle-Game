#include "calcul score.h"

float Calcul_du_score(char tabmots[][26], int temps_limite)
{
    int i, nb_lettre = 0;
    float score_total = 0.0;

    /** Boucle permettant de parcourir le tableau contenant les mots saisis afin d'en calculer le
     * score associé **/

    for(i = 0 ; i < temps_limite * 2 ; i ++)
    {
        nb_lettre = strlen(tabmots[i]); // Calcule du nombre de lettre du mot nécessaire pour le calcul du score
        score_total += (float) pow(nb_lettre, (float) 4/3);  // Incrémentation du score du i-ème mot
    }

    return score_total;
}