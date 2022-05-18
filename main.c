#include "fonctions globales.h" // Bibliothèque des fonctions nécessaires pour l'affichage ou les tests
#include "menu.h" // Bibliothèque pour afficher le menu
#include "generation grille.h" // Bibiliothèque pour générer la grille
#include "menu score.h" // Bibliothèque pour calculer et afficher les scores
#include "mots.h" // Bibliothèque pour saisir les mots et faire la vérification de la langue française
#include "calcul score.h"   //Blibliothèque pour le calcul des scores
#include <stdlib.h>
#include <stdio.h>

int main()
{
    srand(time(NULL));

    // Utilisation du fichier "menu.c"
    short choix = Menu(); // Initialisation du choix de l'utilisateur
    short longueur;

    // Conséquence du choix
    switch (choix)
    {
        case 1: // Lancement de la partie

            // Utilisation du fichier "generation grille.c"
            longueur = Dimension_grille(); // Demande dimension de la grille

            /** Debut du bloc "Definition de la grille" **/
            char grille[8][8];
            Generation_grille(grille, longueur);
            /** Fin du bloc "Definition de la grille" **/

            int temps_limite = 60;//Temps_de_la_partie();

            char** tabmots = (char **) malloc(temps_limite * 2 * sizeof (char*));

            for (int i = 0 ; i < temps_limite * 2 ; ++i)
            {
                tabmots[i] = (char*) malloc(26 * sizeof (char));
            }

            //char tabmots[180][26];

            Saisie_de_mots(temps_limite, grille, longueur, tabmots);
            //Calcul_du_score(tabmots);

            //Calcul_du_score(temps_limite, tabmots);
            break;

        case 2: // Calcul + affichage des scores

            printf("\n WALL OF FAME C-BOGGLE \n");
            printf("-----------------------");
            /* Appel la fonction affichage des scores */
            //Affichage_meilleurs_scores(tabscore);
            break;

        case 3:
            exit(0);
    }

    return 0;
}
