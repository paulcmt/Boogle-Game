#include "fonctions globales.h"

int Comptage_lettre_tableau(char Tabl[], char lettre)
{
    int compteur = 0;

    lettre = toupper(lettre);

    for (int i = 0; i < 8; ++i)
    {
        if (Tabl[i] == lettre)
        {
            compteur = compteur + 1;
        }
    }

    return compteur;
}

void Initialisation_tableau(char tabl[])
{
    for (int i = 0; i < strlen(tabl); ++i)
    {
        tabl[i] = NULL;
    }
}

void Affichage_grille(char grille[8][8], int longueur)
{
    for (int i = 0; i < longueur; ++i)
    {
        for (int j = 0; j < longueur; ++j)
        {
            printf("%c  ", grille[i][j]);
        }
        printf("\n");
    }
}