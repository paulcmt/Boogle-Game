#include "fonctions globales.h" // Bibliothèque des fonctions nécessaires pour l'affichage ou les tests
#include "menu.h" // Bibliothèque pour afficher le menu
#include "generation grille.h" // Bibiliothèque pour générer la grille
#include "menu score.h" // Bibliothèque pour calculer et afficher les scores
#include "mots.h" // Bibliothèque pour saisir les mots et faire la vérification de la langue française
#include "calcul score.h"   //Blibliothèque pour le calcul des scores
#include <stdlib.h>
#include <stdio.h>

/** Début de la partie prototype **/

int Rejouer(short choix_intial);

/** Fin de la partie prototype **/

int Rejouer(short choix_intial)
{
    char choix[4];

    if (choix_intial != 3)
    {
        printf("\nVoulez-vous rejouer (Oui / Non) : ");
        scanf(" %s", choix);

        for (int i = 0; i < 3; ++i)
        {
            choix[i] = toupper(choix[i]);
        }

        while (!(strcmp(choix, "NON") == 0 || strcmp(choix, "OUI") == 0)) // Choix doit être soit OUI soit NON
        {
            printf("\nErreur de saisie, veuillez respecter la casse");
            printf("\nVoulez-vous rejouer (Oui / Non) : ");
            scanf(" %s", choix);

            for (int i = 0; i < 3; ++i)
            {
                choix[i] = toupper(choix[i]);
            }
        }
        /** Fin du bloc "Contrôle du choix avec message d'erreur" **/

        if (strcmp(choix, "OUI") == 0)
        {
            return 3; // Choix vaut 3 donc l'utilisateur va relancer le jeu
        }
        else
        {
            return 1; // Choix vaut 1 donc l'utilisateur ne veut pas relancer le jeu
        }
    }
    else // Choix vaut 3 donc l'utilisateur va relancer le jeu
    {
        return 3;
    }

}

int main()
{
    srand(time(NULL));

    short choix = 0, longueur;

    float score = 0.0;

    do
    {
        // Utilisation du fichier "menu.c"
        choix = Menu(); // Demande du choix de l'utilisateur
        system("clear");

        // Conséquence du choix
        switch (choix)
        {
            case 1: // Lancement de la partie

                // Utilisation du fichier "generation grille.c"
                longueur = Dimension_grille(); // Demande dimension de la grille

                /** Debut du bloc "Definition de la grille" **/
                char grille[8][8];


                grille[0][0] = 'E';
                grille[0][1] = 'D';
                grille[0][2] = 'T';
                grille[0][3] = 'O';
                grille[0][4] = 'R';

                grille[1][0] = 'I';
                grille[1][1] = 'C';
                grille[1][2] = 'M';
                grille[1][3] = 'L';
                grille[1][4] = 'A';

                grille[2][0] = 'L';
                grille[2][1] = 'A';
                grille[2][2] = 'U';
                grille[2][3] = 'E';
                grille[2][4] = 'I';

                grille[3][0] = 'Q';
                grille[3][1] = 'O';
                grille[3][2] = 'T';
                grille[3][3] = 'R';
                grille[3][4] = 'C';

                grille[4][0] = 'R';
                grille[4][1] = 'I';
                grille[4][2] = 'N';
                grille[4][3] = 'P';
                grille[4][4] = 'L';

                //Generation_grille(grille, longueur);
                /** Fin du bloc "Definition de la grille" **/

                int temps_limite = Temps_de_la_partie(); // Demande du temps pour le jeu à l'utilisateur

                /** Début "Création tableau dynamique pour la saisie des mots" **/

                char **tabmots = (char **) malloc(temps_limite * 2 * sizeof(char *)); // Déclaration double pointeur pour tableau dynamique à deux dimensions

                for (int i = 0; i < temps_limite * 2; ++i)
                {
                    tabmots[i] = (char *) malloc(26 * sizeof(char));
                }
                /** Fin "Création tableau dynamique pour la saisie des mots" **/

                Saisie_de_mots(temps_limite, grille, longueur, tabmots); // Saisir un mot + Vérification du mot

                score = Calcul_du_score(tabmots, temps_limite); // Calcul du score de tous les mots saisis

                printf("\nLe score realise dans cette partie est de %.2f points !", score); // Affichage du score

                break;

            case 2: // Affichage des scores

                choix = Menu_scores(); // Appel la fonction menu des scores

                system("clear");

                break;

            case 3:
                exit(0);
        }

        choix = Rejouer(choix);

    } while (choix == 3);

    return 0;
}
