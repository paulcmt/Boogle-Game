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
        fprintf(fichier, "--- FIN FICHIER ---\n");
        fclose(fichier);
    }
    else
    {
        printf("Erreur ouverture");
    }
}

int Nombre_de_lignes()
{
    char score_1[200] = {0}, score_2[200] = {0}, copie_ligne[200]= {0};

    // Variable permettant de contrôler que tout a été trié
    int i = 0, nombre_de_lignes = 0;

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "r"); // Ouverture du fichier des scores

    if (fichier != NULL) // Vérification que le fichier est bien ouvert
    {
        fgets(score_1, 200, fichier); // Acquisition première ligne
        i += strlen(score_1);

        while (strcmp(score_2, "--- FIN FICHIER ---\n") != 0)
        {
            fseek(fichier, i, 0);
            fgets(score_2, 200, fichier);

            strcpy(copie_ligne, score_2); // Sauvegarde de la nouvelle ligne

            if (strncmp(score_1, score_2, 15) < 0) // Si le score 1 est inférieur au score 2
            {
                // Echange des lignes
                i += strlen(score_2);
                strcpy(score_2, score_1);
                strcpy(score_1, copie_ligne);
            }
            else
            {
                i += strlen(score_2);
            }

            nombre_de_lignes ++;
        }
    }

    else
    {
        printf("Echec ouverture");
    }

    fclose(fichier);

    return nombre_de_lignes;
}

void Tri_score()
{
    // Déclaration des variables contenant les lignes à comparer
    char copie_ligne[200]= {0};

    // Variable permettant de contrôler que tout a été trié
    int nombre_de_lignes = 0, permut = 1;

    nombre_de_lignes = Nombre_de_lignes();

    /** Début "Création tableau dynamique pour la saisie des mots" **/
    char **tabscore = (char **) malloc(nombre_de_lignes * sizeof(char *)); // Déclaration double pointeur pour tableau dynamique à deux dimensions

    for (int i = 0; i < nombre_de_lignes; ++i) // Répeter pour toutes les lignes
    {
        tabscore[i] = (char *) malloc(200 * sizeof(char)); // Création d'un tableau de 200 places pour stocker chaque ligne du fichier
    }
    /** Fin "Création tableau dynamique pour la saisie des mots" **/

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "r"); // Ouverture du fichier des scores

    if (fichier != NULL)
    {
        for (int j = 0; j < nombre_de_lignes; ++j)
        {
            fgets(tabscore[j], 200, fichier);
        }

        fclose(fichier);

        while (permut == 1)
        {
            permut = 0;

            for (int k = 0 ; k < nombre_de_lignes - 1; ++k)
            {
                if (strncmp(tabscore[k+1], tabscore[k], 15) > 0)
                {
                    strcpy(copie_ligne, tabscore[k+1]);
                    strcpy(tabscore[k+1], tabscore[k]);
                    strcpy(tabscore[k], copie_ligne);
                    permut = 1;
                }
            }
        }

        fichier = fopen("../score.txt", "w"); // Ouverture du fichier des scores

        if (fichier != NULL)
        {
            for (int l = 0; l < nombre_de_lignes; ++l)
            {
                fprintf(fichier, "%s", tabscore[l]);
            }

            fclose(fichier);
        }

        else
        {
            printf("Echec ouverture");
        }
    }
    else
    {
        printf("Echec ouverture");
    }
}