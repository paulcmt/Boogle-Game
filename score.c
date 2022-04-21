#include "score.h"

void Affichage_meilleurs_scores(char tabscore[])
{
    int i = 0; // Pour établir la boucle

    /* Boucle pour afficher les 10 premiers meilleurs scores enregistrés précédemment
     * dans le tableau à 1 dimension tabscore[] */

    for (i = 0 ; i < 10 ; ++i)
    {
        printf("%d. %d", i + 1, tabscore[i]);
    }
}
