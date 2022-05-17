#include "calcul score.h"

float Calcul_du_score(int temps_limite, char tabmots[temps_limite][26])
{
    int i, nb_lettre = 0;
    float score = 0 , score_total = 0;

    /** Boucle permettant de parcourir le tableau contenant les mots saisis afin d'en calculer le
     * score associé **/

    for(i = 0 ; i < temps_limite ; i = i + 1)
    {
        nb_lettre = strlen(tabmots[i]); // Calcule du nombre de lettre du mot nécessaire pour le calcul du score
        score = pow(nb_lettre, 4/3);  // Calcul du score pour le mot selon la formule donnée par le sujet
        score_total = score_total + score;  // Calcul du score total
    }

    // Affichage du score
    printf("Le score réalise dans cette partie est de %.2f points !\n", score_total);

    /*
     * Si le score en fonction des paramètres de la partie, alors :
     *     - on compare le score avec les autres
     *     - on le met à la bonne place dans le classement
     *
     */



    return score_total;
}