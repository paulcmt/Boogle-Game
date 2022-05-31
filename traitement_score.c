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

