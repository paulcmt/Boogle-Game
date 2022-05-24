#include "menu.h"

int Menu()
{
    /** Debut du bloc "Affichage du menu" **/
    printf("-------- Menu principal ---------\n");
    printf("1. Demarrer une partie\n");
    printf("2. Afficher les meilleurs scores\n");
    printf("3. Quitter\n");
    printf("---------------------------------\n");
    /** Fin du bloc "Affichage du menu" **/

    short choix = 0; // Déclaration variable choix pour le controler

    /** Debut du bloc "Contrôle du choix avec message d'erreur" **/
    fflush(stdin);
    printf("Choix : ");
    scanf(" %hd", &choix);

    while (choix < 1 || choix > 3) // Choix doit être compris entre 1 et 3
    {
        printf("Erreur de saisie, le choix doit être entre 1 et 3"); // Message d'erreur
        fflush(stdin);
        printf("\nChoix : ");
        scanf(" %hd", &choix);
    }
    /** Fin du bloc "Contrôle du choix avec message d'erreur" **/

    return choix; // Retourne le choix de l'utilisateur
}


