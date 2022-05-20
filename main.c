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

    short choix = 0;

    do
    {
        // Utilisation du fichier "menu.c"
        choix = Menu(); // Initialisation du choix de l'utilisateur
        short longueur;
        system("clear");

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

                char **tabmots = (char **) malloc(temps_limite * 2 * sizeof(char *));

                for (int i = 0; i < temps_limite * 2; ++i)
                {
                    tabmots[i] = (char *) malloc(26 * sizeof(char));
                }

                Saisie_de_mots(temps_limite, grille, longueur, tabmots);

                Calcul_du_score(tabmots, temps_limite);

                break;

            case 2: // Affichage des scores

                // Appel la fonction menu des scores
                choix = Menu_scores();
                system("clear");
                break;

            case 3:
                exit(0);
        }

    } while (choix == 3);

    return 0;
}
