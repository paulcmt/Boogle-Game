#include "calcul score.h"

float Calcul_du_score(char tabmots[][26], short temps_limite)
{
    int i, j, nb_lettre = -1;
    float score_total = 0.0;

    /** Boucle permettant de parcourir le tableau contenant les mots saisis afin d'en calculer le
     * score associé **/

    printf("\n\nCalcul des scores");


    for(i = 0 ; i < temps_limite * 2 ; i = i + 1)
    {
        j = -1;
        do
        {
            nb_lettre = nb_lettre + 1;
            j ++;
        }
        while (tabmots[i][j] != NULL);

        score_total = score_total + (float) pow(nb_lettre, (float) 4/3);  // Incrémentation du score du i-ème mot
    }

    free(tabmots);

    return score_total;
}

    /*
     * Où sont tous les mots ?      Ils sont stockés dans "tabmots"
     * Combien y en a t-il ?        Il y en a [i]
     * Score par mots :
     *      Combien de lettres ?    V
     *      Formule --> score temporaire    V
     *      Total   V
     */

    /*
    int Compteur_lettre(char tabmots[][26], short temps_limite)
    {
        j = 0;
        while (tabmots[j] != NULL)
        {
            j = j + 1;
            nb_lettre = nb_lettre + 1;
        }

        return nb_lettre;
    }

    float score = 0;

    for (i = 0 ; i < temps_limite * 2 ; i = i + 1)
    {
        nb_lettre = Compteur_lettre(tabmots[][26], temps_limite);
        score = pow(nb_lettre,4/3);
        score_total = score + score_total;
    }


    return score_total;
}
  */