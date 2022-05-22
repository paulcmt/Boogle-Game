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

    short choix; // Déclaration variable choix pour le controler

    /** Debut du bloc "Contrôle du choix avec message d'erreur" **/
    printf("Choix : ");
    scanf(" %hd", &choix);

    while (choix < 1 || choix > 4) // Choix doit être compris entre 1 et 3
    {
        printf("Erreur de saisie, le choix doit être entre 1 et 3"); // Message d'erreur
        printf("\nChoix : ");
        scanf(" %hd", &choix);
    }
    /** Fin du bloc "Contrôle du choix avec message d'erreur" **/

    return choix; // Retourne le choix de l'utilisateur
}

int Temps_de_la_partie()
{
    short temps = 0;
    printf("Temps voulu pour la partie \(de 60 a 180 secondes\): ");
    scanf("%hd", &temps);

    while (!(60 <= temps && temps <= 180))
    {
        printf("Erreur de saisie, le temps doit être entre 60 et 180 secondes.");
        printf("\nTemps voulu pour la partie \(de 60 a 180 secondes\): ");
        fflush(stdin);
        scanf("%hd", &temps);
    }

    return temps;
}