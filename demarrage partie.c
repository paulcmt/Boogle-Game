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

char Generation_lettre_aleatoire()
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

        case 578 ... 1004: // 427 chances sur 100 000 soit 0,427 %
            lettre = 'X';
            break;

        case 1005 ... 1618: // 614 chances sur 100 000 soit 0,614 %
            lettre = 'J';
            break;

        case 1619 ... 2356: // 738 chances sur 100 000 soit 0,738 %
            lettre = 'H';
            break;

        case 2357 ... 3223: // 867 chances sur 100 000 soit 0,867 %
            lettre = 'G';
            break;

        case 3224 ... 4125: // 902 chances sur 100 000 soit 0,902 %
            lettre = 'B';
            break;

        case 4126 ... 5192: // 1067 chances sur 100 000 soit 1,067 %
            lettre = 'F';
            break;

        case 5193 ... 6555:
            lettre = 'Q';
            break;

        case 6556 ... 8395:
            lettre = 'V';
            break;

        case 8396 ... 10919:
            lettre = 'P';
            break;

        case 10920 ... 13890:
            lettre = 'M';
            break;

        case 13891 ... 17239:
            lettre = 'C';
            break;

        case 17240 ... 20912:
            lettre = 'D';
            break;

        case 20913 ... 26374:
            lettre = 'L';
            break;

        case 26375 ... 32176:
            lettre = 'O';
            break;

        case 32177 ... 38494:
            lettre = 'U';
            break;

        case 38495 ... 45194:
            lettre = 'R';
            break;

        case 45195 ... 52297:
            lettre = 'N';
            break;

        case 52298 ... 59549:
            lettre = 'T';
            break;

        case 59550 ... 67136:
            lettre = 'I';
            break;

        case 67137 ... 75093:
            lettre = 'S';
            break;

        case 75094 ... 83275:
            lettre = 'A';
            break;

        case 83276 ... 100000:
            lettre = 'E';
            break;
    }
    // Fin du bloc "Générer une lettre selon les probabilités"
}
void Generation_grille(char grille[8][8], short longueur)
{


}
