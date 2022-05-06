#include "mots.h"
#include "fonctions globales.h"

int Nb_de_lettres_grille(char grille[8][8], char lettre_a_compter, int longueur)
{
    int compteur = 0;

    for (int i = 0; i < longueur; ++i)
    {
        for (int j = 0; j < longueur; ++j)
        {
            if (grille[i][j] == lettre_a_compter)
            {
                compteur++;
            }
        }
    }

    return compteur;
}

void Coordonnees_lettre(char lettre, int longueur, char grille[8][8], int *L, int *C, int indiceC, int indiceL)
{
    /** Début du bloc "Obtention des coordonnées de la première lettre" **/
    indiceC = -1;
    indiceL = 0;
    int indiceCRetenu = 0; // Va permettre de parcourir la grille

    lettre = toupper(lettre);

    do
    {
        do
        {
            indiceC ++;
        }
        while (indiceC < longueur - 1 && lettre != grille[indiceL][indiceC]);

        indiceL ++;
        indiceCRetenu = indiceC;
        indiceC = -1;
    }
    while (indiceL - 1 < longueur && lettre != grille[indiceL - 1][indiceCRetenu]);
    /** Fin du bloc "Obtention des coordonnées de la première lettre" **/

    *L = indiceL - 1;
    *C = indiceCRetenu;
}

void Obtention_lettres_autour(char lettre_autour[8], int indiceC, int indiceL, char grille[8][8], int longueur)
{
    /** Début du bloc "Obtention des coordonnées de la première lettre" **/

    if (indiceC == 0)
    {
        if (indiceL == 0)
        {
            lettre_autour[0] = grille[0][1];
            lettre_autour[1] = grille[1][0];
            lettre_autour[2] = grille[1][1];
        }
        else if (1 <= indiceL && indiceL <= longueur - 2)
        {
            lettre_autour[0] = grille[indiceL-1][0];
            lettre_autour[1] = grille[indiceL-1][1];
            lettre_autour[2] = grille[indiceL][1];
            lettre_autour[3] = grille[indiceL+1][0];
            lettre_autour[4] = grille[indiceL+1][1];
        }
        else if (indiceL == longueur - 1)
        {
            lettre_autour[0] = grille[indiceL-1][0];
            lettre_autour[1] = grille[indiceL-1][1];
            lettre_autour[2] = grille[indiceL][1];
        }
    }

    else if (indiceC == longueur - 1)
    {
        if (indiceL == 0)
        {
            lettre_autour[0] = grille[0][indiceC-1];
            lettre_autour[1] = grille[1][indiceC-1];
            lettre_autour[2] = grille[1][indiceC];
        }
        else if (1 <= indiceL && indiceL <= longueur - 2)
        {
            lettre_autour[0] = grille[indiceL-1][indiceC-1];
            lettre_autour[1] = grille[indiceL-1][indiceC];
            lettre_autour[2] = grille[indiceL][indiceC-1];
            lettre_autour[3] = grille[indiceL+1][indiceC-1];
            lettre_autour[4] = grille[indiceL+1][indiceC];
        }
        else if (indiceL == longueur - 1)
        {
            lettre_autour[0] = grille[indiceL-1][indiceC-1];
            lettre_autour[1] = grille[indiceL-1][indiceC];
            lettre_autour[2] = grille[indiceL][indiceC-1];
        }
    }

    else if (1 <= indiceC && indiceC <= longueur - 2)
    {
        if (indiceL == 0)
        {
            lettre_autour[0] = grille[0][indiceC - 1];
            lettre_autour[1] = grille[0][indiceC + 1];
            lettre_autour[2] = grille[1][indiceC - 1];
            lettre_autour[3] = grille[1][indiceC];
            lettre_autour[4] = grille[1][indiceC + 1];
        }

        else if (indiceL == longueur - 1)
        {
            lettre_autour[0] = grille[indiceL-1][indiceC - 1];
            lettre_autour[1] = grille[indiceL-1][indiceC];
            lettre_autour[1] = grille[indiceL-1][indiceC + 1];
            lettre_autour[2] = grille[indiceL][indiceC - 1];
            lettre_autour[4] = grille[indiceL][indiceC + 1];
        }

        else if (1 <= indiceL && indiceL <= longueur - 2)
        {
            lettre_autour[0] = grille[indiceL-1][indiceC - 1];
            lettre_autour[1] = grille[indiceL-1][indiceC];
            lettre_autour[2] = grille[indiceL-1][indiceC + 1];
            lettre_autour[3] = grille[indiceL][indiceC - 1];
            lettre_autour[4] = grille[indiceL][indiceC + 1];
            lettre_autour[5] = grille[indiceL+1][indiceC - 1];
            lettre_autour[6] = grille[indiceL+1][indiceC];
            lettre_autour[7] = grille[indiceL+1][indiceC + 1];
        }
    }
}

void Traitement_mot(char tabmots[], char grille[8][8], int longueur)
{
    int mot_dans_grille_verifie = 0, indiceL = 0, indiceC = 0;

    /** Début du bloc de traitement du mot entré **/
    char lettre_autour[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

    char grille_copy[8][8];

    /** Début du bloc "Copie de la grille" pour avoir de quoi différencier les lettres dans la grille **/
    for (int i = 0; i < longueur; ++i)
    {
        for (int j = 0; j < longueur; ++j)
        {
            grille_copy[i][j] = grille[i][j];
        }
    }
    /** Fin du bloc "Copie de la grille" pour avoir de quoi différencier les lettres dans la grille **/

    for (int i = 0; i < strlen(tabmots); ++i)
    {
        Coordonnees_lettre(tabmots[i], longueur, grille, &indiceL, &indiceC, indiceC, indiceL);
        Obtention_lettres_autour(lettre_autour, indiceC, indiceL, grille, longueur);

        /** Début du bloc "Calcul nombres lettres autoures" **/
        int nb_lettres_autour = -1, j = 0;
        do
        {
            nb_lettres_autour ++;
            j++;
        }
        while(lettre_autour[j] != 0);
        /** Fin du bloc "Calcul nombres lettres autoures" **/

        while (Comptage_lettre_tableau(lettre_autour, tabmots[i+1], nb_lettres_autour) == 0)
        {
            if (tabmots[i+1] == '\0')
            {
                mot_dans_grille_verifie = 0;
                break;
            }
            if (indiceC != longueur - 1)
            {
                indiceC ++;
            }
            else
            {
                indiceC = 0;
                indiceL ++;
            }

            Coordonnees_lettre(tabmots[i], longueur, grille, &indiceL, &indiceC, indiceC, indiceL);
            Obtention_lettres_autour(lettre_autour, indiceC, indiceL, grille, longueur);
        }
        grille_copy[indiceL][indiceC] = ' ';
    }

    Affichage_grille(grille_copy, longueur);
    /** Fin du bloc de traitement du mot entré **/
}

void Saisie_de_mots(int temps_limite, char grille[8][8], int longueur)
{

    /* Le stockage des mots se fera dans un tableau dont la dimension
     * dépendra du temps de jeu et de la taille de la grille
     * En effet on considère un vitesse max d'un mot par seconde et la longueur max sera celle du mot
     * français le plus long (anticonstitutionellement) soit 25 lettres => 26 caractères */

    int i = 0; // Permet de pouvoir boucler

    char tabmots[temps_limite][26];

    // Tant que le temps imparti n'est pas écouler alors l'utilisateur peut saisir un mot
    //while (/** Compteur de temps **/)
    //{
        printf("Saisir un mot : \n");
        scanf("%s", &tabmots[i]); // Le mot taper se trouvera à la i-ème ligne
        Traitement_mot(tabmots[i], grille, longueur);
        i ++; // Incrémentation de i pour pouvoir passer au mot suivant
    //}
}
