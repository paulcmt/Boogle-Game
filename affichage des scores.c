#include "affichage des scores.h"
#include "fonctions globales.h"

int Dimension_grille_score() // Demande la dimension de la grille
{
    char dimension[4]; // Création de la future réponse de l'utilisateur
    Initialisation_tableau(dimension); // Tout élément devient NULL

    printf("Grille voulue pour les scores (de 4 a 8) : ");
    fflush(stdin);
    fgets(dimension, 4, stdin); // Demande à l'utilisateur la dimension de la grille

    while (!(strcmp(dimension, "4x4") == 0 || strcmp(dimension, "5x5") == 0 || strcmp(dimension, "6x6") == 0 ||
             strcmp(dimension, "7x7") == 0 || strcmp(dimension, "8x8") == 0 || strcmp(dimension, "4\n") == 0
             || strcmp(dimension, "5\n") == 0 || strcmp(dimension, "6\n") == 0 || strcmp(dimension, "7\n") == 0
             || strcmp(dimension, "8\n") == 0)) // Contrôle de la dimension
    {
        printf("Erreur de saisie, la dimension doit etre entre 4 et 8\n");
        printf("Grille voulue pour les scores (de 4 a 8) : ");
        fflush(stdin);
        fgets(dimension, 4, stdin); // Demande à l'utilisateur la dimension de la grille
    }

    return atoi(&dimension[0]); // Longueur de la grille = premier caractère de la saisie de l'utilisateur
}

void Affichage_par_grille(short dimension_grille, short longueur_fichier)
{
    short indice_grille_fichier = 0, affichage_presentation = 0;
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
                affichage_presentation ++;

                if (affichage_presentation == 1)
                {
                    printf("-------------- Score(s) de la grille %d --------------\n", dimension_grille);
                    printf("%s", ligne);
                }
                else
                {
                    printf("%s", ligne);
                }
            }

            indice_grille_fichier = 0;
        }

        if (affichage_presentation != 0)
        {
            printf("------------------------------------------------------\n");
        }
        else
        {
            printf("----------------------------------------------------\n");
            printf("Pas de score enregistree pour cette taille de grille\n");
            printf("----------------------------------------------------\n");
        }
    }

    else
    {
        printf("Erreur ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }

    fclose(fichier);
}

void Affichage_par_pseudo(short longueur_fichier)
{
    char pseudo[100] = {0}, ligne[256] = {0}, copie_ligne[256] = {0};
    short indice_pseudo_ligne = 0, nb_caractere_valide = 0, affichage_presentation = 0;

    printf("Nom du joueur a chercher : ");
    fflush(stdin);
    fgets(pseudo, 100, stdin);

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "r");

    if (fichier != NULL)
    {
        pseudo[strlen(pseudo) - 1] = NULL;

        for (short i = 0 ; i < longueur_fichier ; i++)
        {
            fgets(ligne, 256, fichier);
            strcpy(copie_ligne, ligne);

            while (ligne[indice_pseudo_ligne] != 'm')
            {
                indice_pseudo_ligne ++;
            }

            indice_pseudo_ligne += 4;

            for (int k = indice_pseudo_ligne; k < strlen(pseudo)+indice_pseudo_ligne; ++k)
            {
                pseudo[k-indice_pseudo_ligne] = toupper(pseudo[k-indice_pseudo_ligne]);
                copie_ligne[k] = toupper(copie_ligne[k]);
            }

            for (int j = 0; j < strlen(pseudo); ++j)
            {
                if (copie_ligne[indice_pseudo_ligne] == pseudo[j])
                {
                    nb_caractere_valide ++;
                }
                else
                {
                    nb_caractere_valide = 0;
                    break;
                }

                indice_pseudo_ligne ++;
            }

            if (nb_caractere_valide == strlen(pseudo))
            {
                affichage_presentation ++;

                if (affichage_presentation == 1)
                {
                    pseudo[0] = toupper(pseudo[0]);
                    for (int l = 1; l < strlen(pseudo); ++l)
                    {
                        pseudo[l] = tolower(pseudo[l]);
                    }

                    printf("-------------- Score(s) du joueur %s --------------\n", pseudo);
                    printf("%s", ligne);
                }
                else
                {
                    printf("%s", ligne);
                }
            }

            indice_pseudo_ligne = 0;
            nb_caractere_valide = 0;
        }

        if (affichage_presentation != 0)
        {
            printf("---------------------------------");
            for (int q = 0; q < strlen(pseudo); ++q)
            {
                printf("-");
            }
            printf("----------------\n");
        }
        else
        {
            printf("---------------------------------------\n");
            printf("Pas de score enregistree pour ce joueur\n");
            printf("---------------------------------------\n");
        }

    }

    else
    {
        printf("Erreur ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }

    fclose(fichier);
}