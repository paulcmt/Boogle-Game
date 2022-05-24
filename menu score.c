#include "menu score.h"
#include "generation grille.h"

int Menu_scores()
{
    /** Debut du bloc "Affichage du menu score" **/
    printf("-------- Menu des scores --------\n");
    printf("1. Recherche du score d'un joueur\n");
    printf("2. Meilleurs scores par grille\n");
    printf("3. Retour au menu principal\n");
    printf("---------------------------------\n");
    /** Fin du bloc "Affichage du menu score" **/

    short choix; // Déclaration variable choix pour le controler

    /** Debut du bloc "Contrôle du choix avec message d'erreur" **/
    fflush(stdin);
    printf("Choix : ");
    scanf(" %hd", &choix);

    while (!(choix >=1 && choix <= 3)) // Choix doit être compris entre 1 et 3
    {
        printf("Erreur de saisie, le choix doit être entre 1 et 3."); // Message d'erreur
        fflush(stdin);
        printf("\nChoix : ");
        scanf(" %hd", &choix);
    }
    /** Fin du bloc "Contrôle du choix avec message d'erreur" **/

    return choix; // Retourne le choix de l'utilisateur
}

void Recherche_par_joueur()
{
    char nom_de_joueur_recherche[26];

    /** Début du bloc pour obtenir le nom d'un joueur à rechercher dans le fichier des scores **/

    printf("Quel joueur voulez vous rechercher ?\n");
    fgets(nom_de_joueur_recherche,26,stdin);

    /** Début du bloc pour obtenir le nom d'un joueur à rechercher dans le fichier des scores **/

    /** Bloc d'envoie et de recherche dans le fichier des scores **/

}

void Scores_par_grille()
{
    int dim_grille;

    // Récupération des dimensions de la grille dont on souhaite voir les scores

    dim_grille = Dimension_grille();
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