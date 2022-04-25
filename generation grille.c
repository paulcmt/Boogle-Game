#include "generation grille.h"
#include "fonctions globales.h"

int Dimension_grille() // Demande la dimension de la grille
{
    char dimension_grille[4]; // Création de la future réponse de l'utilisateur pour la dimension de la grille
    Initialisation_tableau(dimension_grille); // Tout élément devient NULL

    printf("Dimension souhaitee de la grille \(de 4x4 jusqu'a 8x8\) : ");
    scanf("%s", &dimension_grille); // Demande à l'utilisateur la dimension de la grille la grille (dimension carrée)

    while (!(strcmp(dimension_grille, "4x4") == 0 || strcmp(dimension_grille, "5x5") == 0 || strcmp(dimension_grille, "6x6") == 0 ||
            strcmp(dimension_grille, "7x7") == 0 || strcmp(dimension_grille, "8x8") == 0 ))
    {
        printf("Erreur de saisie, la dimension doit etre entre 4x4 et 8x8.\n");
        printf("Dimension souhaitee de la grille \(de 4x4 jusqu'à 8x8\) : ");
        fflush(stdin);
        scanf("%s", &dimension_grille); // Redemande à l'utilisateur la dimension de la grille
    }

    return atoi(&dimension_grille[0]); // Longueur de la grille = premier caractère de la saisie de l'utilisateur
}

char Generation_lettre_aleatoire()
{
    /** Debut du bloc "Générer une lettre selon les probabilités" **/
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
    /** Fin du bloc "Générer une lettre selon les probabilités" **/

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

void Lettre_commune3_0(char sous_carre3x3[9]) // Vérification que les 3 nouvelles lettres ne sont pas en double entre elles et dans le sous carre 3x3
{
    int i,j; // Variables permettant de parcourir et de comparer les lettres du sous carre 3x3

    for (i = 6; i < 9; i++) // Pour juste comparer les 3 nouvelles lettres car les 6 autres sont déja différentes entre elles
    {
        for (j = 0; j < 9; ++j) // Permet la comparaison des nouvelles lettres aux 6 autres et entre elleds
        {
            if (sous_carre3x3[i] == sous_carre3x3[j] && i != j /* Eviter de comparer les lettres du meme indice car forcément égales*/)
            {
                sous_carre3x3[i] = Generation_lettre_aleatoire(); // Génération d'une nouvelle lettre selon les probabilités
                j = -1; // Va permettre de comparer la nouvelle lettre générée aux autres pour voir si elle est en double donc on reprend à 0
                // On met j = -1 car la boucle va incrémenter j de 1 donc au recommencement j vaudra 0 et c'est ce qu'on veut
            }
        }
    }
}

void Lettre_commune4_0(char sous_carre3x3[9]) // Vérifie si présence de nouvelle lettre
{
    sous_carre3x3[8] = Generation_lettre_aleatoire();

    for (int j = 0; j < 8; ++j)
    {
        if (sous_carre3x3[8] == sous_carre3x3[j])
        {
            sous_carre3x3[8] = Generation_lettre_aleatoire();
            j = -1;
        }
    }
}

void Assignation_sous_carre_vers_grille(char grille[8][8], char sous_carre3x3[9]) // Placemment du sous carré 3x3 de base dans la grille
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

void Creation_des_lettres_a_droite_premier(char grille[8][8], char sous_carre3x3[9], short longueur)
{
    char nouveau_sous_carre3x3[9]; // Nouveau sous carré 3x3 pour permettre le décalage du sous carré vers la droite
    short indice = 3; // Permet le placement des nouvelles lettres genérées au bon endroit

    for (int i = 0; i < longueur - 3; ++i)
    /* Permet le décalage du sous carré vers la droite autant de fois
     * que nécéssaire (si longueur = 5 alors décalage 2 fois pour
     * remplir la grille) */
    {
        for (int j = 0; j < 9; ++j) // Création et association du nouveau sous carré
        {
            if (j != 2 && j != 5 && j != 8) // Selectionne uniquement les lettres du sous carré précédent
            {
                nouveau_sous_carre3x3[j] = sous_carre3x3[j+1]; // On décale les lettres du sous carré précédent dans le nouveau sous carré
            }
            else
            {
                nouveau_sous_carre3x3[j] = Generation_lettre_aleatoire(); // Génération d'une nouvelle lettre
            }
        }

        Lettre_commune2_0(nouveau_sous_carre3x3); // Comparer si les nouvelles sont en double parmis les 6 lettres à droite du sous carré précédent
        memcpy(sous_carre3x3, nouveau_sous_carre3x3, 9); // Décalage du sous carré, on passe le nouveau sous carré généré en tant qu'ancien sous carré

        /** Debut du bloc "Assignation à la grille des nouvelles lettres genérées" **/
        grille[0][indice] = sous_carre3x3[2]; // Si longueur = 5 alors placer la nouvelle lettre après la troisième valeur de la ligne
        grille[1][indice] = sous_carre3x3[5];
        grille[2][indice] = sous_carre3x3[8];
        /** Fin du bloc "Assignation à la grille des nouvelles lettres genérées" **/

        indice ++; // Va permettre de déplacer les lettres d'un cran vers la droite au prochain déplacement de sous carré
    }
}

void Decalage_en_bas_et_vers_la_droite(char grille[8][8], char sous_carre3x3[9], short longueur)
{
    short nouvelle_longueur = 4;
    /* Taille minimale de la grille qui va permettre de descendre et décaler
     * vers la droite autant de fois que nécéssaire */

    for (int k = 0; k < longueur-3; ++k)
        /* Descendre dans la grille autant que nécessaire, si longueur = 5 alors
         * descendre 2 fois car il y a déjà un sous carre de 3x3 au dessus */
    {
        for (int j = 0; j < 9; ++j) // Descente du sous carré d'une ligne vers le bas
        {
            if (j < 3)
            {
                sous_carre3x3[j] = grille[k+1][j]; // La 2 ème ligne de l'ancien sous carré devient la 1 ère
            }
            else if (3 <= j && j < 6)
            {
                sous_carre3x3[j] = grille[k+2][j-3]; // La 3 ème ligne de l'ancien sous carré devient la 2 ème
            }
            else
            {
                sous_carre3x3[j] = Generation_lettre_aleatoire(); // La 3 ème ligne du sous carré va être constituée de nouvelles lettres
            }
        }

        Lettre_commune3_0(sous_carre3x3); // Vérification que les 3 nouvelles lettres ne sont pas en double entre elles et dans le sous carre 3x3

        /** Debut du bloc "Assignation des 3 nouvelles lettres du sous carré à la grille" **/
        grille[nouvelle_longueur-1][0] = sous_carre3x3[6]; // nouvelle_longueur permet de sélectionner la bonne ligne
        grille[nouvelle_longueur-1][1] = sous_carre3x3[7];
        grille[nouvelle_longueur-1][2] = sous_carre3x3[8];
        /* le sous carré générant 3 lettres n'est réalisé qu'à chaque
         * nouvelle ligne donc les indices de la deuxième dimension sont corrects */
        /** Fin du bloc "Assignation des 3 nouvelles lettres du sous carré à la grille" **/

        for (int i = 0; i < longueur-3; ++i)
        {
            sous_carre3x3[0] = grille[k+1][i+1];
            sous_carre3x3[1] = grille[k+1][i+2];
            sous_carre3x3[2] = grille[k+1][i+3];
            sous_carre3x3[3] = grille[k+2][i+1];
            sous_carre3x3[4] = grille[k+2][i+2];
            sous_carre3x3[5] = grille[k+2][i+3];
            sous_carre3x3[6] = grille[k+3][i+1];
            sous_carre3x3[7] = grille[k+3][i+2];

            Lettre_commune4_0(sous_carre3x3);
            grille[nouvelle_longueur-1][i+3] = sous_carre3x3[8];
        }
        nouvelle_longueur ++;
    }
}
void Generation_grille(char grille[8][8], short longueur) // Fonction pour générer la grille de la taille souhaitée
{
    /** Debut du bloc "Génération du sous carre 3x3 de base" **/
    char sous_carre3x3[9]; // Création du sous carré 3x3
    Generation_sous_carre3x3(sous_carre3x3); // Attribution des lettres dans le sous carré 3x3
    Lettre_commune(sous_carre3x3); // Vérifie si présence de lettres similaires dans le sous carré
    /** Fin du bloc "Génération du sous carre 3x3 de base" **/

    Assignation_sous_carre_vers_grille(grille, sous_carre3x3); // Assignation du sous carré 3x3 de base à la grille

    Creation_des_lettres_a_droite_premier(grille, sous_carre3x3, longueur); // Création des lettres vers la droite jusqu'au bout de la grille

    Decalage_en_bas_et_vers_la_droite(grille, sous_carre3x3, longueur);
}
