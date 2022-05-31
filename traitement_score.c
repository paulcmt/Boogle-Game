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

void Tri_score()
{
    // Déclaration des variables contenant les lignes à comparer
    char score_1[256] = {0}, score_2[256] = {0}, copie_ligne[256]= {0};

    // Variable permettant de contrôler que tout a été trié
    int controle = 1;

    // Ouverture du fichier
    FILE *fichier_score = NULL;
    fichier_score = fopen("../score", "r+"); // Ouverture du fichier des scores

    if (fichier_score != NULL) // Vérification que le fichier est bien ouvert
    {
        fgets(score_1, 256, fichier_score); // Acquisition première ligne

        // Tant que les scores ne sont pas triés et que le fichier n'a pas été parcouru
        while (controle != 0 && score_1 != NULL && score_2 != NULL)
        {
            controle = 0; // Réinitilisation de la variable de contrôle

            /*
            if (score_2 == NULL)
            {

            }
            else
            {
                fgets(score_2, 256, fichier_score); // Acquisition deuxième ligne
            }
            */

            fgets(score_2, 256, fichier_score); // Acquisition deuxième ligne

            strcpy(copie_ligne, score_2); // Sauvegarde de la nouvelle ligne

            /** Bloc de tri des scores **/
            if (strncmp(score_1, score_2, 12) < 0) // Si le score 1 est inférieur au score 2
            {
                controle = controle + 1; // Incrémentation de de la variable de contrôle car le tri n'est pas fait

                /** Echange des lignes **/
                strcpy(score_2, score_1);
                strcpy(score_1, copie_ligne);
            }
        }
    }
}

