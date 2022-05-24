#include "calcul score.h"

float Calcul_du_score(char tabmots[][26], int temps_limite)
{
    int i, j, nb_lettre = -1;
    float score_total = 0.0;

    /** Boucle permettant de parcourir le tableau contenant les mots saisis afin d'en calculer le
     * score associé **/

    printf("Calcul des scores");

    for(i = 0 ; i < temps_limite * 2 ; i ++)
    {
        j = 0;
        do
        {
            nb_lettre ++;
        }
        while (tabmots[i][j] != '\0');

        score_total += (float) pow(nb_lettre, (float) 4/3);  // Incrémentation du score du i-ème mot
    }

    free(tabmots);

    return score_total;
}