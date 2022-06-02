#include "affichage des scores.h"
#include "fonctions globales.h"

void Affichage_par_grille(short dimension_grille, short longueur_fichier)
{
    // Déclaration des variables permettant de traiter la demande de l'utilisateur
    short indice_grille_fichier = 0;
    char ligne[256] = {0};

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "r"); // Ouverture du fichier

    if (fichier != NULL) // Vérification de l'ouverture du fichier
    {
        for (short i = 0 ; i < longueur_fichier ; i++) // Boucle permettant de parcourir l'entièreté du fichier
        {
            fgets(ligne, 256, fichier); // Acquisition de la ligne à analyser

            while (ligne[indice_grille_fichier] != '\n') // Boucle permettant de compter le nombre de caractères de la ligne analysée
            {
                indice_grille_fichier ++; // Incrémentation du nombre de caractère
            }

            if (atoi(&ligne[indice_grille_fichier-1]) == dimension_grille) // Si l'avant dernier caractère (correspondant à la grille où a été réalisé le score) est égal à la dimension recherchée
            {
                printf("%s", ligne); // Affichage de la ligne à l'utilisateur
            }

            indice_grille_fichier = 0; // Réinitialisation du nombre de caractère
        }
    }

    else
    {
        printf("Erreur ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }

    fclose(fichier); // Fermeture du fichier
}

void Recherche_par_pseudo(short longueur_fichier)
{
    short i, position_ligne = 0, position_pseudo = 0;
    char ligne[256] = {0}, pseudo[26] = {0};

    printf("De quel joueur souhaitez vous afficher les scores ?");
    fgets(pseudo, 26, stdin);

    FILE *fichier = NULL;
    fichier = fopen("../score.txt","r");

    if (fichier != NULL)
    {
        for(i = 0 ; i < longueur_fichier ; i = i + 1)
        {
            position_ligne = 0;
            position_pseudo = 0;

            fgets(ligne, 256, fichier);
        }
    }
    else
    {
        printf("Erreur ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }

    fclose(fichier); // Fermeture du fichier
}