#include "traitement_score.h"
#include "fonctions globales.h"

void Enregistrement_score(float score, short longueur)
{
    char pseudo[26];
    printf("\nVeuillez saisir votre prenom : ");
    fflush(stdin);
    scanf(" %s", &pseudo);

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "a");

    if (fichier != NULL)
    {
        fprintf(fichier, "Score : %.2f Prenom : %s Grille : %hd\n", score, pseudo, longueur);
        fclose(fichier);
    }
    else
    {
        printf("Erreur ouverture");
    }

}

void tri_score()
{
    char score_1[256], score_2[256];

    FILE *fichier_score = NULL;
    fichier_score = fopen("../score", "r+");

    if (fichier_score != NULL)
    {

    }
}

