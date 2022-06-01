#include "affichage des scores.h"
#include "fonctions globales.h"

void Affichage_par_grille(int dimension_grille, int longueur_fichier)
{
    int i = 0, j = 0, emplacement_dimension = 0;
    char ligne_lue[256] = {0};

    FILE *fichier;
    fopen("../score.txt", "r");

    if (fichier != NULL)
    {
        for (j = 0 ; j < longueur_fichier ; j = j + 1)
        {
            fgets(ligne_lue, 256, fichier);
            i+= strlen(ligne_lue);

            while (ligne_lue[emplacement_dimension] != NULL)
            {
                emplacement_dimension = emplacement_dimension + 1;
            }

            if ( ligne_lue[emplacement_dimension] == dimension_grille)
            {
                printf("%s\n", ligne_lue);
            }
        }
    }
    else
    {
        printf("Erreur ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }

    fclose(fichier);
}