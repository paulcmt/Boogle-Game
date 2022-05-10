#include "score.h"
#include "generation grille.h"

void recherche_par_joueur()
{
    char nom_de_joueur_recherche[26];

    /** Début du bloc pour obtenir le nom d'un joueur à rechercher dans le fichier des scores **/

    printf("Quel joueur voulez vous rechercher ?\n");
    fgets(nom_de_joueur_recherche,26,stdin);

    /** Début du bloc pour obtenir le nom d'un joueur à rechercher dans le fichier des scores **/

    /** Bloc d'envoie et de recherche dans le fichier des scores **/

}

void scores_par_grille()
{
    int dim_grille;

    // Récupération des dimensions de la grille dont on souhaite voir les scores

    dim_grille = Dimension_grille();
}


int Affichage_meilleurs_scores(char tabscore[])
{
    int repscore;

    printf("Menu des scores :\n");
    printf("1) Recherche du score d'un joueur\n 2) Meilleurs scores par grille\n 3) EXIT\n");
    scanf("%d", &repscore);     // Récupération du choix du joueur

    switch (repscore) {
        case 1 :
            recherche_par_joueur();     // Envoi vers la recherche par joueur
            break;

        case 2:
            scores_par_grille();    // Envoie vers la recherche par dimension de grille
            break;

        case 3 :
            break;

    }

}


/*
 * int i = 0; // Pour établir la boucle

    /* Boucle pour afficher les 10 premiers meilleurs scores enregistrés précédemment
     * dans le tableau à 1 dimension tabscore[] */
/*
for (i = 0 ; i < 10 ; ++i)
{
printf("%d. %d", i + 1, tabscore[i]);
}
 */