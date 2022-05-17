#include "calcul score.h"

float Calcul_du_score(int temps_limite, char tabmots[temps_limite][26])
{
    int i, nb_lettre = 0;
    float score = 0 , score_total = 0;

    /** Boucle permettant de parcourir le tableau contenant les mots saisis afin d'en calculer le
     * score associé **/

    for(i = 0 ; i < temps_limite ; i = i + 1)
    {
        nb_lettre = strlen(tabmots[i]);
        score = pow(nb_lettre, 4/3);
        score_total = score_total + score;
    }

    printf("Le score réalise dans cette partie est de %.2f points !\n", score_total);

    return score_total;
}