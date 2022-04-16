#include "generation grille.h"
#include "fonctions globales.h"

int Dimension_grille() // Demande la dimension de la grille
{
    char dimension_grille[4]; // Création de la future réponse de l'utilisateur pour la dimension de la grille
    Initialisation_tableau(dimension_grille); // Tout élément devient NULL

    printf("Quelle est la dimension souhaitee \(de 4x4 jusqu'a 8x8\) : ");
    scanf("%s", &dimension_grille); // Demande à l'utilisateur la dimension de la grille

    // Vérification de la saisie de la dimension de la grille (dimension carrée)
    while (!(strcmp(dimension_grille, "4x4") == 0 || strcmp(dimension_grille, "5x5") == 0 || strcmp(dimension_grille, "6x6") == 0 ||
            strcmp(dimension_grille, "7x7") == 0 || strcmp(dimension_grille, "8x8") == 0 ))
    {
        printf("Erreur de saisie, la dimension doit etre entre 4x4 et 8x8.\n");
        printf("Quelle est la dimension souhaitee \(de 4x4 jusqu'à 8x8\) : ");
        fflush(stdin);
        scanf("%s", &dimension_grille); // Redemande à l'utilisateur la dimension de la grille
    }

    return atoi(&dimension_grille[0]); // Longueur de la grille = premier caractère de la saisie de l'utilisateur
}

char Generation_lettre_aleatoire()
{
    // Debut du bloc "Générer une lettre selon les probabilités"
    int nb_random_lettre = rand() % 99999 + 1; // Tire un nombre random entre 1 et 100 000

    char lettre = NULL; // Intialisation de la variable qui contiendra la lettre

    switch (nb_random_lettre) // Association du nombre tiré à la lettre correspondante
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

        case 5193 ... 6555: // 1363 chances sur 100 000 soit 1,363 %
            lettre = 'Q';
            break;

        case 6556 ... 8395: // 1840 chances sur 100 000 soit 1,840 %
            lettre = 'V';
            break;

        case 8396 ... 10919: // 2524 chances sur 100 000 soit 2,524 %
            lettre = 'P';
            break;

        case 10920 ... 13890: // 2971 chances sur 100 000 soit 2,971 %
            lettre = 'M';
            break;

        case 13891 ... 17239: // 3349 chances sur 100 000 soit 3,349 %
            lettre = 'C';
            break;

        case 17240 ... 20912: // 3673 chances sur 100 000 soit 3,673 %
            lettre = 'D';
            break;

        case 20913 ... 26374: // 5462 chances sur 100 000 soit 5,462 %
            lettre = 'L';
            break;

        case 26375 ... 32176: // 5802 chances sur 100 000 soit 5,802 %
            lettre = 'O';
            break;

        case 32177 ... 38494: // 6318 chances sur 100 000 soit 6,318 %
            lettre = 'U';
            break;

        case 38495 ... 45194: // 6700 chances sur 100 000 soit 6,700 %
            lettre = 'R';
            break;

        case 45195 ... 52297: // 7103 chances sur 100 000 soit 1,067 %
            lettre = 'N';
            break;

        case 52298 ... 59549: // 7252 chances sur 100 000 soit 7,252 %
            lettre = 'T';
            break;

        case 59550 ... 67136: // 7587 chances sur 100 000 soit 7,587 %
            lettre = 'I';
            break;

        case 67137 ... 75093: // 7957 chances sur 100 000 soit 7,957 %
            lettre = 'S';
            break;

        case 75094 ... 83275: // 8182 chances sur 100 000 soit 8,182 %
            lettre = 'A';
            break;

        case 83276 ... 100000: // 16726 chances sur 100 000 soit 16,726 %
            lettre = 'E';
            break;
    }
    // Fin du bloc "Générer une lettre selon les probabilités"

    return lettre;
}

void Generation_sous_carre3x3(char sous_carre3x3[9]) // Première partie de la génération de la grille
{
    for (int i = 0; i < 9; ++i)
    {
        sous_carre3x3[i] = Generation_lettre_aleatoire();
    }
}

void Lettre_commune(char sous_carre3x3[9]) // Vérifie si présence de lettre commune dans un tableau donné
{
    int i,j;

    for (i = 0; i < 9; ++i)
    {
        for (j = i; j < 9; ++j)
        {
            if (sous_carre3x3[i] == sous_carre3x3[j] && i != j) // Si présence lettre similaire
            {
                sous_carre3x3[i] = Generation_lettre_aleatoire(); // Génération nouvelle lettre aléatoirement
                j = -1; // Va permettre de comparer la nouvelle lettre générée aux autres pour voir si doublon
            }
        }
    }

}

void Lettre_commune2_0(char sous_carre3x3[9]) // Vérifie si présence de nouvelle lettre
{
    int i,j;

    for (i = 2; i < 9; i = i + 3)
    {
        for (j = 0; j < 9; ++j)
        {
            if (sous_carre3x3[i] == sous_carre3x3[j] && i != j) // Si présence lettre similaire
            {
                sous_carre3x3[i] = Generation_lettre_aleatoire(); // Génération nouvelle lettre aléatoirement
                j = -1; // Va permettre de comparer la nouvelle lettre générée aux autres pour voir si doublon
            }
        }
    }

}
void Assignation_sous_carre_vers_grille(char grille[8][8], char sous_carre3x3[9])
{
    short indice = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            grille[i][j] = sous_carre3x3[indice];
            indice++;
        }
    }
}

void Decalage_a_droite(char grille[8][8], char sous_carre3x3[9], short longueur)
{
    char nouveau_sous_carre3x3[9];
    short indice = 3; // Permet de placer les nouvelles lettres au bon endroit

    for (int i = 0; i < longueur - 3; ++i) // Génération des 3 prochaines lettres
    {
        for (int j = 0; j < 9; ++j)
        {
            if (j != 2 && j != 5 && j != 8)
            {
                nouveau_sous_carre3x3[j] = sous_carre3x3[j+1]; //On remet les lettres ud sous carré précédent
            }
            else
            {
                nouveau_sous_carre3x3[j] = Generation_lettre_aleatoire(); // Génération d'une nouvelle lettre
            }
        }
        Lettre_commune2_0(nouveau_sous_carre3x3); // Comparer si les nouvelles sont en double
        memcpy(sous_carre3x3, nouveau_sous_carre3x3, 9); // Décalage du sous carré

        // Debut du bloc "Assignation à la grille des nouvelles lettres"
        grille[0][indice] = sous_carre3x3[2];
        grille[1][indice] = sous_carre3x3[5];
        grille[2][indice] = sous_carre3x3[8];
        // Fin du bloc "Assignation à la grille des nouvelles lettres"

        indice ++; // Va permettre de déplacer les lettres vers la droite au prochain déplacement de sous carré
    }
}
void Generation_grille(char grille[8][8], short longueur)
{
    // Debut du bloc "Génération du sous carre 3x3"
    char sous_carre3x3[9]; // Création du sous carré 3x3
    Generation_sous_carre3x3(sous_carre3x3); // Attribution des lettres dans le sous carré 3x3
    Lettre_commune(sous_carre3x3); // Vérifie si présence de lettres similaires dans le sous carré
    // Fin du bloc "Génération du sous carre 3x3"

    Assignation_sous_carre_vers_grille(grille, sous_carre3x3); // Assignation du sous carré à la grille

    Decalage_a_droite(grille, sous_carre3x3, longueur); // Décalage vers la droite du sous carre + génération des 3 prochaines lettres + assignation à la grille

    Affichage_grille(grille, 5);
}
