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
        }
        /** Fin du bloc "Contrôle du choix avec message d'erreur" **/

        if (strcmp(choix, "OUI"))
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
        choix = 1;//Menu(); // Demande du choix de l'utilisateur
        system("clear");

        // Conséquence du choix
        switch (choix)
        {
            case 1: // Lancement de la partie

                // Utilisation du fichier "generation grille.c"
                longueur = 7; //Dimension_grille(); // Demande dimension de la grille

                /** Debut du bloc "Definition de la grille" **/
                char grille[8][8];
                /*
                grille[0][0] = 'I';
                grille[0][1] = 'O';
                grille[0][2] = 'G';
                grille[0][3] = 'E';
                grille[0][4] = 'O';
                grille[0][5] = 'R';
                grille[0][6] = 'N';

                grille[1][0] = 'N';
                grille[1][1] = 'P';
                grille[1][2] = 'A';
                grille[1][3] = 'D';
                grille[1][4] = 'I';
                grille[1][5] = 'T';
                grille[1][6] = 'S';

                grille[2][0] = 'S';
                grille[2][1] = 'U';
                grille[2][2] = 'R';
                grille[2][3] = 'S';
                grille[2][4] = 'P';
                grille[2][5] = 'L';
                grille[2][6] = 'E';

                grille[3][0] = 'I';
                grille[3][1] = 'D';
                grille[3][2] = 'E';
                grille[3][3] = 'X';
                grille[3][4] = 'T';
                grille[3][5] = 'A';
                grille[3][6] = 'M';

                grille[4][0] = 'O';
                grille[4][1] = 'G';
                grille[4][2] = 'P';
                grille[4][3] = 'T';
                grille[4][4] = 'A';
                grille[4][5] = 'Q';
                grille[4][6] = 'I';

                grille[5][0] = 'R';
                grille[5][1] = 'A';
                grille[5][2] = 'S';
                grille[5][3] = 'V';
                grille[5][4] = 'C';
                grille[5][5] = 'U';
                grille[5][6] = 'L';

                grille[6][0] = 'I';
                grille[6][1] = 'V';
                grille[6][2] = 'E';
                grille[6][3] = 'M';
                grille[6][4] = 'D';
                grille[6][5] = 'E';
                grille[6][6] = 'F';*/

                Generation_grille(grille, longueur);
                /** Fin du bloc "Definition de la grille" **/

                int temps_limite = 60;//Temps_de_la_partie(); // Demande du temps pour le jeu à l'utilisateur

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
