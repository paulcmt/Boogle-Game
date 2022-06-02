#include "affichage des scores.h"
#include "fonctions globales.h"

int Affichage_par_grille(short dimension_grille, short longueur_fichier)
{
    short i = 0, j = 0, emplacement_dimension = 0, recherche_suivante = 0, dimscorecomp = 0;
    char ligne_lue[256] = {0}, reponse[4], dim_score[3];

    FILE *fichier;
    fopen("../score.txt", "r");

    if (fichier != NULL)
    {
        for (i = 0 ; i < longueur_fichier ; i = i + 1)
        {
            fgets(ligne_lue, 256, fichier);

            while (ligne_lue[emplacement_dimension] != '\n')
            {
                emplacement_dimension = emplacement_dimension + 1;
            }

            dim_score[0] = ligne_lue[emplacement_dimension];

            dimscorecomp = atoi(&dim_score[0]);

            if (dim_score == dimension_grille)
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

    printf("Voulez visualiser d'autres scores ? (oui/non)");
    fgets(reponse, 4, stdin);

    for(j = 0 ; j < 4 ; j = j + 1)
    {
        reponse[i] = toupper(reponse[i]);
    }

    if (strcmp(reponse, "OUI") == 0)
    {
        recherche_suivante = 0;
    }
    else
    {
        recherche_suivante = 1;
    }

    return recherche_suivante;
}