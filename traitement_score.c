#include "traitement_score.h"
#include "fonctions globales.h"

void Suppression_fin_fichier()
{
    int nombre_de_lignes = Nombre_de_lignes(); // Récupération du nombre de ligne contenu par le fichier

    /** Début "Création tableau dynamique pour la saisie des mots" **/
    char **tabscore = (char **) malloc(nombre_de_lignes * sizeof(char *)); // Déclaration double pointeur pour tableau dynamique à deux dimensions

    for (int i = 0; i < nombre_de_lignes; ++i) // Répeter pour toutes les lignes
    {
        tabscore[i] = (char *) malloc(200 * sizeof(char)); // Création d'un tableau de 200 places pour stocker chaque ligne du fichier
    }
    /** Fin "Création tableau dynamique pour la saisie des mots" **/

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "r"); // Ouverture du fichier des scores

    if (fichier != NULL) // Vérification que le fichier est bien ouvert
    {
        for (int j = 0; j < nombre_de_lignes; ++j) // Tant que le fichier n'a pas été entièrement parcouru :
        {
            fgets(tabscore[j], 200, fichier); // Récupération de la j-ième ligne du fichier
        }

        fclose(fichier); // Fermeture du fichier
    }
    else
    {
        printf("Echec ouverture");
    }

    fichier = fopen("../score.txt", "w"); // Ouverture du fichier des scores

    if (fichier != NULL) // Vérification que le fichier est bien ouvert
    {
        for (int l = 0; l < nombre_de_lignes; ++l)
        {
            fprintf(fichier, "%s", tabscore[l]); // On réécrit tous les scores triés dans le fichier
        }

        fclose(fichier); // Fermeture du fichier
    }
    else
    {
        printf("Echec ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }

}

void Enregistrement_score(float score, short longueur)
{
    char pseudo[26];

    /** Début du bloc de saisi du nom du joueur **/
    printf("\nVeuillez saisir votre prenom : ");
    fflush(stdin);
    scanf(" %s", &pseudo);
    /** Fin du bloc de saisi du nom du joueur **/

    Suppression_fin_fichier();

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "a"); // OUverture du fichier contenant les  scores

    if (fichier != NULL) // Vérification que le fichier est bien ouvert
    {
        fprintf(fichier, "Score : %.2f Prenom : %s Grille : %hd\n", score, pseudo, longueur); // Stockage des données de la partie
        fprintf(fichier, "--- FIN FICHIER ---\n"); // Signalement de la fin du texte contenu par le fichier
        fclose(fichier); // Fermeture du fichier des scores
    }
    else
    {
        printf("Erreur ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }
}

int Nombre_de_lignes() // Fonction permettant de savoir combien de lignes contient le fichier score
{
    char score_1[200] = {0}, score_2[200] = {0}, copie_ligne[200]= {0};

    // Variable permettant d'effectuer que le tri
    int i = 0, nombre_de_lignes = 0;

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "r"); // Ouverture du fichier des scores

    if (fichier != NULL) // Vérification que le fichier est bien ouvert
    {
        fgets(score_1, 200, fichier); // Acquisition première ligne
        i += strlen(score_1); // Incrémentation de la position du curseur dans le fichier

        while (strcmp(score_2, "--- FIN FICHIER ---\n") != 0) // Tant qu'on est pas à la fin du contenu du fichier :
        {

            fseek(fichier, i, 0);
            fgets(score_2, 200, fichier); // Acquisition de la 2e ligne

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
                i += strlen(score_2); // Incrémentation du curseur de lecture
            }

            nombre_de_lignes ++; // Incrémentation du nombre de ligne
        }

        fclose(fichier); // Fermeture du fichier des scores
    }
    else
    {
        printf("Echec ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }

    return nombre_de_lignes; // Renvoie du nombre de ligne contenu par le fichier
}

void Tri_score()
{
    // Déclaration des variables contenant les lignes à comparer
    char copie_ligne[200]= {0};

    // Variable permettant de contrôler que tout a été trié
    int nombre_de_lignes = 0, permutation = 1;

    nombre_de_lignes = Nombre_de_lignes(); // Récupération du nombre de ligne contenu par le fichier

    /** Début "Création tableau dynamique pour la saisie des mots" **/
    char **tabscore = (char **) malloc(nombre_de_lignes * sizeof(char *)); // Déclaration double pointeur pour tableau dynamique à deux dimensions

    for (int i = 0; i < nombre_de_lignes; ++i) // Répeter pour toutes les lignes
    {
        tabscore[i] = (char *) malloc(200 * sizeof(char)); // Création d'un tableau de 200 places pour stocker chaque ligne du fichier
    }
    /** Fin "Création tableau dynamique pour la saisie des mots" **/

    FILE *fichier = NULL;
    fichier = fopen("../score.txt", "r"); // Ouverture du fichier des scores

    if (fichier != NULL) // Vérification que le fichier est bien ouvert
    {
        for (int j = 0; j < nombre_de_lignes; ++j) // Tant que le fichier n'a pas été entièrement parcouru :
        {
            fgets(tabscore[j], 200, fichier); // Récupération de la j-ième ligne du fichier
        }

        fclose(fichier); // Fermeture du fichier

        /** Début du bloc de tri du tableau **/
        while (permutation == 1) // Tant qu'une permutation est effectuée :
        {
            permutation = 0; // Réinitialisation de la variable permutation

            for (int k = 0 ; k < nombre_de_lignes - 1; ++k)
            {
                if (strncmp(tabscore[k+1], tabscore[k], 15) > 0) // Comparaison des score. Si le score de la ligne suivante est suppérieur alors :
                {
                    strcpy(copie_ligne, tabscore[k+1]); // Sauvegarde de la ligne suivante
                    strcpy(tabscore[k+1], tabscore[k]); // La ligne suivante reçoit la valeur la plus faible
                    strcpy(tabscore[k], copie_ligne); // La ligne étudiée reçoit la valeur la plus élevée
                    permutation = 1; // Incrémentation pour signaler qu'une permutation a été effectuée
                }
            }
        }
        /** Fin du bloc de tri du tableau **/

        fichier = fopen("../score.txt", "w"); // Ouverture du fichier des scores

        if (fichier != NULL) // Vérification que le fichier est bien ouvert
        {
            for (int l = 0; l < nombre_de_lignes; ++l)
            {
                fprintf(fichier, "%s", tabscore[l]); // On réécrit tous les scores triés dans le fichier
            }

            fprintf(fichier, "--- FIN FICHIER ---\n"); // Signalement de la fin du texte contenu par le fichier
            fclose(fichier); // Fermeture du fichier
        }

        else
        {
            printf("Echec ouverture"); // Signalement de l'échec de l'ouverture du fichier
        }
    }
    else
    {
        printf("Echec ouverture"); // Signalement de l'échec de l'ouverture du fichier
    }
}