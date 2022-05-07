#include "mots.h"
#include "fonctions globales.h"

int Nb_de_lettres_grille(char grille[8][8], char lettre_a_compter, int longueur)
{
    int compteur = 0;
    lettre_a_compter = toupper(lettre_a_compter);

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

void Coordonnees_lettre(char lettre, int longueur, char grille[8][8], int *indiceL, int *indiceC)
{
    /** Début du bloc "Obtention des coordonnées de la première lettre" **/
    *indiceC = *indiceC - 1;
    int indiceCRetenu = 0; // Va permettre de parcourir la grille

    lettre = toupper(lettre);

    do
    {
        do
        {
            *indiceC = *indiceC + 1;
        }
        while (*indiceC < longueur - 1 && lettre != grille[*indiceL][*indiceC]);

        *indiceL = *indiceL + 1;
        indiceCRetenu = *indiceC;
        *indiceC = -1;
    }
    while (*indiceL - 1 < longueur && lettre != grille[*indiceL - 1][indiceCRetenu]);
    /** Fin du bloc "Obtention des coordonnées de la première lettre" **/

    *indiceL = *indiceL - 1;
    *indiceC = indiceCRetenu;
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
            lettre_autour[2] = grille[indiceL-1][indiceC + 1];
            lettre_autour[3] = grille[indiceL][indiceC - 1];
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

int Position_lettre_tab_lettre_autour(char lettre_autour[8], char lettre, int longueur)
{
    int i = -1;

    lettre = toupper(lettre);

    do
    {
        i = i + 1;
    }
    while (longueur > i && lettre_autour[i] != lettre);

    return i;
}

int Traitement_mot(char mot[], char grille[8][8], int longueur)
{
    int mot_dans_grille_verifie = 0, indiceL = 0, indiceC = 0, indiceLPrecedent = 0, indiceCPrecedent = 0;
    int nb_lettres_verifiees = 0;
    /** Début du bloc de traitement du mot entré **/
    char lettre_autour[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

    for (int k = 0; k < Nb_de_lettres_grille(grille, mot[k], longueur)-1; ++k)
    {
        Coordonnees_lettre(mot[k], longueur, grille, &indiceL, &indiceC);

        int i, nb_lettres_autour;

        for (i = 0; i < strlen(mot) - 1; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                lettre_autour[j] = NULL;
            }

            Obtention_lettres_autour(lettre_autour, indiceC, indiceL, grille, longueur);

            /** Début du bloc "Calcul nombres lettres autoures" **/
            nb_lettres_autour = -1;
            int j = 0;
            do
            {
                nb_lettres_autour ++;
                j++;
            }
            while(lettre_autour[j] != 0);
            /** Fin du bloc "Calcul nombres lettres autoures" **/

            indiceLPrecedent = indiceL;
            indiceCPrecedent = indiceC;

            if (Comptage_lettre_tableau(lettre_autour, mot[i+1]) > 0)
            {
                indiceLPrecedent = indiceL;
                indiceCPrecedent = indiceC;
                /** Debut du bloc "Position lettre suivante" **/
                if (indiceC == 0)
                {
                    if (indiceL == 0)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceL = 0;
                                indiceC = 1;
                                break;
                            case 1:
                                indiceL = 1;
                                indiceC = 0;
                                break;
                            case 2:
                                indiceL = 1;
                                indiceC = 1;
                                break;
                        }
                    }
                    else if (1 <= indiceL && indiceL <= longueur - 2)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceL = indiceL - 1;
                                break;
                            case 1:
                                indiceL = indiceL - 1;
                                indiceC = indiceC + 1;
                                break;
                            case 2:
                                indiceC = indiceC + 1;
                                break;
                            case 3:
                                indiceL = indiceL + 1;
                                break;
                            case 4:
                                indiceL = indiceL + 1;
                                indiceC = indiceC + 1;
                                break;
                        }
                    }
                    else if (indiceL == longueur - 1)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceL = indiceL - 1;
                                break;
                            case 1:
                                indiceL = indiceL - 1;
                                indiceC = indiceC + 1;
                                break;
                            case 2:
                                indiceC = indiceC + 1;
                                break;
                        }
                    }
                }

                else if (indiceC == longueur - 1)
                {
                    if (indiceL == 0)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceC = indiceC - 1;
                                break;
                            case 1:
                                indiceL = indiceL + 1;
                                indiceC = indiceC - 1;
                                break;
                            case 2:
                                indiceL = indiceL + 1;
                                break;
                        }
                    }
                    else if (1 <= indiceL && indiceL <= longueur - 2)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceL = indiceL - 1;
                                indiceC = indiceC - 1;
                                break;
                            case 1:
                                indiceL = indiceL - 1;
                                break;
                            case 2:
                                indiceC = indiceC - 1;
                                break;
                            case 3:
                                indiceL = indiceL + 1;
                                indiceC = indiceC - 1;
                                break;
                            case 4:
                                indiceL = indiceL + 1;
                                break;
                        }
                    }
                    else if (indiceL == longueur - 1)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceL = indiceL - 1;
                                indiceC = indiceC - 1;
                                break;
                            case 1:
                                indiceL = indiceL - 1;
                                break;
                            case 2:
                                indiceC = indiceC - 1;
                                break;
                        }
                    }
                }

                else if (1 <= indiceC && indiceC <= longueur - 2)
                {
                    if (indiceL == 0)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceC = indiceC - 1;
                                break;
                            case 1:
                                indiceC = indiceC + 1;
                                break;
                            case 2:
                                indiceL = indiceL + 1;
                                indiceC = indiceC - 1;
                                break;
                            case 3:
                                indiceL = indiceL + 1;
                                break;
                            case 4:
                                indiceL = indiceL + 1;
                                indiceC = indiceC + 1;
                                break;
                        }
                    }

                    else if (indiceL == longueur - 1)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceL = indiceL - 1;
                                indiceC = indiceC - 1;
                                break;
                            case 1:
                                indiceL = indiceL - 1;
                                break;
                            case 2:
                                indiceL = indiceL - 1;
                                indiceC = indiceC + 1;
                                break;
                            case 3:
                                indiceC = indiceC - 1;
                                break;
                            case 4:
                                indiceC = indiceC + 1;
                                break;
                        }
                    }

                    else if (1 <= indiceL && indiceL <= longueur - 2)
                    {
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[i+1], nb_lettres_autour))
                        {
                            case 0:
                                indiceL = indiceL - 1;
                                indiceC = indiceC - 1;
                                break;
                            case 1:
                                indiceL = indiceL - 1;
                                break;
                            case 2:
                                indiceL = indiceL - 1;
                                indiceC = indiceC + 1;
                                break;
                            case 3:
                                indiceC = indiceC - 1;
                                break;
                            case 4:
                                indiceC = indiceC + 1;
                                break;
                            case 5:
                                indiceL = indiceL + 1;
                                indiceC = indiceC - 1;
                                break;
                            case 6:
                                indiceL = indiceL + 1;
                                break;
                            case 7:
                                indiceL = indiceL + 1;
                                indiceC = indiceC + 1;
                                break;
                        }
                    }
                }
                /** Fin du bloc "Position lettre suivante" **/
                printf("Lettre suivante trouvée\n");
                nb_lettres_verifiees = nb_lettres_verifiees + 1;
            }

            else
            {
                k = k - 1;
                nb_lettres_verifiees = 0;
                printf("Lettre suivante introuvable\n");

                if (indiceCPrecedent == longueur - 1)
                {
                    indiceL = indiceLPrecedent + 1;
                    indiceC = 0;
                    break;
                }

                else
                {
                    indiceL = indiceLPrecedent;
                    indiceC = indiceCPrecedent + 1;
                    break;
                }
            }

        }
    }

    if (nb_lettres_verifiees == strlen(mot)-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    /** Fin du bloc de traitement du mot entré **/
}

void Saisie_de_mots(int temps_limite, char grille[8][8], int longueur)
{

    /* Le stockage des mots se fera dans un tableau dont la dimension
     * dépendra du temps de jeu et de la taille de la grille
     * En effet on considère un vitesse max d'un mot par seconde et la longueur max sera celle du mot
     * français le plus long (anticonstitutionellement) soit 25 lettres => 26 caractères */

    int i = 0; // Permet de pouvoir boucler
    int mot_verif = 0;
    char tabmots[temps_limite][26];

    for (int j = 0; j < temps_limite; ++j)
    {
        for (int k = 0; k < 26; ++k)
        {
            tabmots[j][k] = NULL;
        }
    }

    // Tant que le temps imparti n'est pas écouler alors l'utilisateur peut saisir un mot
    //while (/** Compteur de temps **/)
    //{
    printf("Saisir un mot : \n");
    scanf("%s", &tabmots[i]); // Le mot taper se trouvera à la i-ème ligne
    printf("%d", strlen(tabmots[i]));
    mot_verif = Traitement_mot(tabmots[i], grille, longueur);
    printf("%d", mot_verif);
    //i = i + 1; // Incrémentation de i pour pouvoir passer au mot suivant
    //}
}
