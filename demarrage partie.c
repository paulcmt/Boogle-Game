#include "demarrage partie.h"
#include "fonctions globales.h"

int Dimension_grille() // Demande la dimension de la grille
{
    char dimension_grille[4]; // Création de la future réponse de l'utilisateur pour la dimension de la grille
    Initialisation_tableau(dimension_grille); // Tout élément devient NULL
    short longueurlargeur = 0; // Variable pour créer la grille qui sera affectée après

    printf("Quelle est la dimension souhaitée \(de 4x4 jusqu'à 8x8\) : ");
    scanf("%s", &dimension_grille); // Demande à l'utilisateur la dimension de la grille

    // Vérification de la saisie de la dimension de la grille (dimension carrée)
    while (!(strcmp(dimension_grille, "4x4") == 0 || strcmp(dimension_grille, "5x5") == 0 || strcmp(dimension_grille, "6x6") == 0 ||
            strcmp(dimension_grille, "7x7") == 0 || strcmp(dimension_grille, "8x8") == 0 ))
    {
        printf("Erreur de saisie, la dimension doit être entre 4x4 et 8x8.\n");
        printf("Quelle est la dimension souhaitée \(de 4x4 jusqu'à 8x8\) : ");
        scanf(" %s", &dimension_grille); // Redemande à l'utilisateur la dimension de la grille
    }
}