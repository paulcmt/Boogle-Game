#include "calcul score.h"

int Calcul_du_score(int temps_limite, char tabmots[temps_limite][26])
{
    int i, nb_lettre = 0;
    float score = 0 , score_total = 0;

    for(i = 0 ; i < temps_limite ; i = i + 1)
    {
        nb_lettre = strlen(tabmots[i]);
        score = pow(nb_lettre, 4/3);
        score_total = score_total + score;
    }

    printf("Le score réalise dans cette partie est de %.2f points !\nBravo !\n", score_total);

    return score_total;
}