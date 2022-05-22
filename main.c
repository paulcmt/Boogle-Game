#include "fonctions globales.h"
#include "menu.h"
#include "generation grille.h"
#include "menu score.h"
#include "mots.h"
#include "calcul score.h"

#include <stdlib.h>
#include <stdio.h>

/** Début du bloc "Prototype des fonctions dans le main" **/

int Temps_de_la_partie(); // Fonctionnel + commenté
int Rejouer(short choix_intial);

/** Fin du bloc "Prototype des fonctions dans le main" **/

/** Début du bloc "Définition des fonctions dans le main" **/

int Temps_de_la_partie()
{
    short temps = 0;

    /** Debut du bloc "Contrôle du temps limite avec message d'erreur" **/
    printf("Temps voulu pour la partie \(de 60 a 180 secondes\): ");
    scanf(" %hd", &temps);

    while (60 < temps || temps > 180) // Temps entre doit être compris entre 60 et 180 secondes
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

/** Fin du bloc "Définition des fonctions dans le main" **/

int main()
{
    srand(time(NULL));

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

                Generation_grille(grille, longueur); // Generation de la grille

                temps_limite = Temps_de_la_partie(); // Demande du temps pour le jeu à l'utilisateur

                /** Début "Création tableau dynamique pour la saisie des mots" **/

                char **tabmots = (char **) malloc(temps_limite * 2 * sizeof(char *)); // Déclaration double pointeur pour tableau dynamique à deux dimensions

                for (int i = 0; i < temps_limite * 2; ++i)
                {
                    tabmots[i] = (char *) malloc(26 * sizeof(char));
                }

                /** Fin "Création tableau dynamique pour la saisie des mots" **/

                Saisie_de_mots(temps_limite, grille, longueur, tabmots); // Saisir un mot + vérification du mot

                score = Calcul_du_score(tabmots, temps_limite); // Calcul du score de tous les mots saisis

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
