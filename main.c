#include "fonctions globales.h"
#include "menu.h"
#include "generation grille.h"
#include "menu score.h"
#include "mots.h"
#include "calcul score.h"

#include <stdlib.h>
#include <stdio.h>

/** Début du bloc "Prototype des fonctions dans le main" **/

/**
 * Demande le temps limite pour effectuer une partie à l'utilisateur
 * @return temps
 */
int Temps_de_la_partie(); // Fonctionnel + commenté

/**
 * Permet de demander au joueur si il veut rejouer seulement si il vient de finir une partie
 * @param choix_intial
 * @return 1 ou 3
 */
int Rejouer(short choix_intial); // Fonctionnel + commenté

/** Fin du bloc "Prototype des fonctions dans le main" **/

/** Début du bloc "Définition des fonctions dans le main" **/

int Temps_de_la_partie()
{
    short temps = 0;

    printf("Temps voulu pour la partie \(de 60 a 180 secondes\): ");
    scanf(" %hd", &temps);

    /** Debut du bloc "Contrôle du temps limite avec message d'erreur" **/
    while (60 > temps || temps > 180) // Temps entre doit être compris entre 60 et 180 secondes
    {
        printf("Erreur de saisie, le temps doit être entre 60 et 180 secondes"); // Message d'erreur
        printf("\nTemps voulu pour la partie \(de 60 a 180 secondes\): ");
        scanf(" %hd", &temps);
    }
    /** Fin du bloc "Contrôle du temps limite avec message d'erreur" **/

    return temps; // Retourne le temps limite choisi
}

int Rejouer(short choix_intial)
{
    char choix[4]; // Déclaration de la variable réponse de l'utilisateur sous forme de string

    if (choix_intial != 3)

    /* Si l'utilisateur est passé par le menu des scores et veut retourner au
     * menu principal, on ne lui demande pas si il veut rejouer donc condition nécessaire */

    {
        printf("\nVoulez-vous rejouer (Oui / Non) : ");
        fgets(choix, 3, stdin);
        fflush(stdin);

        for (int i = 0; i < 3; ++i) // On passe la réponse de l'utilisateur en majuscules pour effectuer la vérification plus loin
        {
            choix[i] = toupper(choix[i]);
        }

        /** Début du bloc "Contrôle du choix avec message d'erreur" **/
        while (!(strcmp(choix, "NON") == 0 || strcmp(choix, "OUI") == 0)) // Réponse doit être soit oui soit non
        {
            printf("\nErreur de saisie, veuillez respecter la casse"); // Message d'erreur
            printf("\nVoulez-vous rejouer (Oui / Non) : ");

            fgets(choix, 3, stdin);
            fflush(stdin);

            for (int i = 0; i < 3; ++i) // On passe la réponse de l'utilisateur en majuscules pour effectuer la vérification plus loin
            {
                choix[i] = toupper(choix[i]);
            }
        }
        /** Fin du bloc "Contrôle du choix avec message d'erreur" **/

        if (strcmp(choix, "OUI") == 0) // Si l'utilisateur veut rejouer alors on retourne 3 pour que la boucle du main continue de tourner
        {
            return 3; // Choix vaut 3 donc l'utilisateur va relancer le jeu
        }
        else
        {
            return 1; // Choix vaut 1 donc l'utilisateur ne veut pas relancer le jeu
        }
    }

    else // Choix vaut 3 par défaut car l'utilisateur est passé par le menu des scores donc veut juste le menu principal
    {
        return 3;
    }

}

/** Fin du bloc "Définition des fonctions dans le main" **/

int main()
{
    srand(time(NULL)); // Intialisation du générateur aléatoire

    /** Début du bloc "Déclaration des variables nécessaires au programme" **/
    short choix = 0, longueur = 0, temps_limite = 0;
    float score = 0.0;
    char grille[8][8];
    /** Fin du bloc "Déclaration des variables nécessaires au programme" **/

    do
    {
        choix = Menu(); // Demande du choix de l'utilisateur

        switch (choix)
        {
            case 1: // Lancement de la partie

                longueur = Dimension_grille(); // Demande dimension de la grille

                /*
                grille[5][0] = 'P';
                grille[5][1] = 'E';
                grille[5][2] = 'M';
                grille[5][3] = 'S';
                grille[5][4] = 'N';
                grille[5][5] = 'Z';

                grille[4][0] = 'S';
                grille[4][1] = 'D';
                grille[4][2] = 'F';
                grille[4][3] = 'U';
                grille[4][4] = 'T';
                grille[4][5] = 'P';

                grille[3][0] = 'L';
                grille[3][1] = 'T';
                grille[3][2] = 'O';
                grille[3][3] = 'A';
                grille[3][4] = 'U';
                grille[3][5] = 'E';

                grille[2][0] = 'A';
                grille[2][1] = 'R';
                grille[2][2] = 'E';
                grille[2][3] = 'N';
                grille[2][4] = 'D';
                grille[2][5] = 'O';

                grille[1][0] = 'H';
                grille[1][1] = 'J';
                grille[1][2] = 'I';
                grille[1][3] = 'C';
                grille[1][4] = 'T';
                grille[1][5] = 'R';

                grille[0][0] = 'C';
                grille[0][1] = 'S';
                grille[0][2] = 'L';
                grille[0][3] = 'A';
                grille[0][4] = 'U';
                grille[0][5] = 'E';*/

                Generation_grille(grille, longueur); // Generation de la grille

                temps_limite = Temps_de_la_partie(); // Demande du temps pour le jeu à l'utilisateur

                /** Début "Création tableau dynamique pour la saisie des mots" **/

                char **tabmots = (char **) malloc(temps_limite * 2 * sizeof(char *)); // Déclaration double pointeur pour tableau dynamique à deux dimensions

                for (int i = 0; i < temps_limite * 2; ++i) // Répeter pour toutes les lignes
                {
                    tabmots[i] = (char *) malloc(26 * sizeof(char)); // Création d'un tableau de 26 places pour stocker un mot
                }

                /** Fin "Création tableau dynamique pour la saisie des mots" **/

                Saisie_de_mots(temps_limite, grille, longueur, tabmots); // Saisir un mot + vérification du mot

                printf("\nLe score realise dans cette partie est de %.2f points !", score); // Affichage du score

                break;

            case 2: // Affichage des scores

                choix = Menu_scores(); // Appel la fonction menu des scores

                break;

            case 3:
                exit(0);

            default: // Permet de faire les tests si choix = 4
                break;
        }

        choix = Rejouer(choix);

    } while (choix == 3);

    return 0;
}
