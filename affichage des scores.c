#include "affichage des scores.h"
#include "fonctions globales.h"

void Affichage_par_grille(short dimension_grille, short longueur_fichier)
{
    short indice_grille_fichier = 0;
    char ligne[256] = {0};

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "r");

    if (fichier != NULL)
    {
        for (short i = 0 ; i < longueur_fichier ; i++)
        {
            fgets(ligne, 256, fichier);

            while (ligne[indice_grille_fichier] != '\n')
            {
                indice_grille_fichier ++;
            }

            if (atoi(&ligne[indice_grille_fichier-1]) == dimension_grille)
            {
                printf("%s", ligne);
            }

            indice_grille_fichier = 0;
        }
    }

    else
    {
        printf("Erreur ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }

    fclose(fichier);
}