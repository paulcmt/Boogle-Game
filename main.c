#include "fonctions globales.h"
#include "menu.h"
#include "generation grille.h"

int main()
{
    srand(time(NULL));

    // Utilisation du fichier "menu.c"
    short choix = Menu(); // Initialisation du choix de l'utilisateur
    short longueur;

    //Conséquence du choix
    switch (choix)
    {
        case 1 : // Le choix est de lancer une partie

            // Utilisation du fichier "generation grille.c"
            longueur = Dimension_grille();

            /** Debut du bloc "Definition de la grille" **/
            char grille[8][8];
            Generation_grille(grille, longueur);
            /** Fin du bloc "Definition de la grille" **/

            short temps_limite = Temps_de_la_partie();

            //Saisie_de_mots(temps_limite);

        break;

        case 2 : // Appel des scores
            printf("\n WALL OF FAME C-BOGGLE \n");
            printf("-----------------------");
            /** Appel la fonction affichage des scores **/
            //Affichage_meilleurs_scores(tabscore);
        break;

        case 3 : // Sortie du jeu avec message d'au revoir

            printf("\nA bientot !\n");
            exit(0);

        break;
    }

    return 0;
}
