#include "demarrage partie.h"
#include "fonctions globales.h"

int Dimension_grille() // Demande la dimension de la grille
{
    char dimension_grille[4]; // Création de la future réponse de l'utilisateur pour la dimension de la grille
    Initialisation_tableau(dimension_grille); // Tout élément devient NULL

    printf("Quelle est la dimension souhaitée \(de 4x4 jusqu'à 8x8\) : ");
    scanf("%s", &dimension_grille); // Demande à l'utilisateur la dimension de la grille

    // Vérification de la saisie de la dimension de la grille (dimension carrée)
    while (!(strcmp(dimension_grille, "4x4") == 0 || strcmp(dimension_grille, "5x5") == 0 || strcmp(dimension_grille, "6x6") == 0 ||
            strcmp(dimension_grille, "7x7") == 0 || strcmp(dimension_grille, "8x8") == 0 ))
    {
        printf("Erreur de saisie, la dimension doit être entre 4x4 et 8x8.\n");
        printf("Quelle est la dimension souhaitée \(de 4x4 jusqu'à 8x8\) : ");
        fflush(stdin);
        scanf("%s", &dimension_grille); // Redemande à l'utilisateur la dimension de la grille
    }

    return atoi(&dimension_grille[0]); // Longueur de la grille = premier caractère de la saisie de l'utilisateur
}

void Generation_grille(char grille[8][8], short longueur)
{
    // Debut du bloc "Générer une lettre selon les probabilités"
    int nb_random_lettre = rand() % 99999 + 1; // Tire un nombre random entre 1 et 100 000
    char lettre = NULL;
    switch (nb_random_lettre)
    {
        case 1 ... 49: // 49 chances sur 100 000 soit 0,049 %
            lettre = 'W';
            break;

        case 50 ... 123: // 74 chances sur 100 000 soit 0,074 %
            lettre = 'K';
            break;

        case 124 ... 251: // 128 chances sur 100 000 soit 0,128 %
            lettre = 'Y';
            break;

        case 252 ... 577: // 326 chances sur 100 000 soit 0,326 %
            lettre = 'Z';
            break;

        case 578 ... 1004: // 427 chances sur 100 000 soit
            lettre = 'X';
            break;
    }
    // Fin du bloc "Générer une lettre selon les probabilités"
    /*
    for (int i = 0; i < longueur; ++i)
    {
        for (int j = 0; j < longueur; ++j)
        {
            grille[i][j] = 'A';
        }
    }
     */
}
