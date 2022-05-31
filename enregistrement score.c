#include "enregistrement score.h"
#include "fonctions globales.h"

void enregistrement_score(float score, short longueur)
{
    char pseudo[26];
    printf("\nVeuillez saisir votre prenom : ");
    fflush(stdin);
    scanf(" %s", &pseudo);

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "a");

    if (fichier != NULL)
    {
        fprintf(fichier, "Grille : %hd Prenom : %s Score : %.2f\n", longueur, pseudo, score);
        fclose(fichier);
    }
    else
    {
        printf("Erreur ouverture");
    }

}

