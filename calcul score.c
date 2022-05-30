#include "calcul score.h"

float Calcul_du_score(char tabmots[][26], short nb_de_mots_valides)
{
    short i, j, nb_lettre;
    float score_total = 0.0;

    /* Boucle permettant de parcourir le tableau contenant les mots saisis afin d'en calculer le
     * score associé */

    for(i = 0 ; i < nb_de_mots_valides; i = i + 1) // Boucle permettant de donner le score pour chaque mot trouvé
    {
        j = -1;
        nb_lettre = -1; // Initialization du nombre de lettre contenu par le mot
        do
        {
            nb_lettre ++; // Comptage du nombre de lettre composant le mot
            j ++; // Parcours du mot
        }
        while (tabmots[i][j] != NULL);

        score_total = score_total + (float) pow(nb_lettre, (float) 4/3);  // Incrémentation du score du i-ème mot
        // Incrémentation du score total en ajoutant le score que donne le mot au score total du joueur
    }

    free(tabmots); // Libération de mémoire du tableau dynamique

    return score_total; // Renvoie du score du joueur sur la partie qu'il vient d'effectuer
}