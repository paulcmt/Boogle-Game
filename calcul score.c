#include "calcul score.h"

float Calcul_du_score(char tabmots[][26], short nb_de_mots_valides)
{
    short i, j, nb_lettre;
    float score_total = 0.0;

    /* Boucle permettant de parcourir le tableau contenant les mots saisis afin d'en calculer le
     * score associé */

    for(i = 0 ; i < nb_de_mots_valides; i = i + 1)
    {
        j = -1;
        nb_lettre = -1;
        do
        {
            nb_lettre ++;
            j ++;
        }
        while (tabmots[i][j] != NULL);

        score_total = score_total + (float) pow(nb_lettre, (float) 4/3);  // Incrémentation du score du i-ème mot
    }

    free(tabmots);

    return score_total;
}