#include "mots.h"
#include "fonctions globales.h"

/** Bloc fonction permettant de savoir combien de fois la première lettre est présente dans la grille**
 * @param grille
 * @param lettre_a_compter
 * @param longueur
 * @return
 */

int Nb_de_lettres_grille(char grille[8][8], char lettre_a_compter, int longueur)
{
    int compteur = 0;

    /** Est-ce qu'on toupper le mot là ??**/

    lettre_a_compter = toupper(lettre_a_compter); // Passage en majuscule obligatoire pour comparer

    for (int i = 0; i < longueur; ++i)  // Boucle permettant de parcourir la grille
    {
        for (int j = 0; j < longueur; ++j)
        {
            if (grille[i][j] == lettre_a_compter)
            {
                compteur++; // Quand on trouve la lettre on incrémente un compteur
            }
        }
    }

    return compteur; // On récupère la valeur du compteur pour pouvoir l'utiliser dans l'analyse du mot
}

/** Fin du bloc de comptage de la première lettre **/

void Coordonnees_lettre(char lettre, int longueur, char grille[8][8], int *indiceL, int *indiceC)
{
    /** Début du bloc "Obtention des coordonnées de la première lettre" **/

    *indiceC = *indiceC - 1;
    int indiceCRetenu = 0; // Va permettre de parcourir la grille

    lettre = toupper(lettre);   // Passage en majuscule obligatoire pour comparer

    /** Début de la boucle permettant de récupérer les coordonnées **/

    do
    {
        // Boucle permettant de parcourir la grille à la recherche de la lettre dans une même ligne

        do
        {
            *indiceC = *indiceC + 1;    //passage à la lettre de droite
        }
        while (*indiceC < longueur - 1 && lettre != grille[*indiceL][*indiceC]);

        // Fin de la boucle

        *indiceL = *indiceL + 1;    // Passage à la ligne suivante
        indiceCRetenu = *indiceC;   // Récupération de l'indice colonne de la lettre si trouvée ou de la dernière colonne.
        *indiceC = -1;              // On réinitialise l'indice colonne pour continuer à parcourir la grille si nécessaire.
    }
    while (*indiceL - 1 < longueur && lettre != grille[*indiceL - 1][indiceCRetenu]);

    // On répète la boucle tant la lettre ne correspond pas aux coordonnées proposées

    /** Fin de la boucle permettant de récupérer les coordonnées **/

    /** Fin du bloc "Obtention des coordonnées de la première lettre" **/

    // Sauvegarde des coordonées trouvées

    *indiceL = *indiceL - 1;
    *indiceC = indiceCRetenu;
}

void Obtention_lettres_autour(char lettre_autour[8], int indiceC, int indiceL, char grille[8][8], int longueur)
{
    /** Début du bloc "Obtention des coordonnées de la première lettre" **/
    /** Début du bloc nous permettant de récupérer les différentes lettres autour de celle étudiée **/

    // Bloc de récupération spécifique à la première colonne de la grille car conditions particulières

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

    // Bloc de récupération spécifique à la dernière colonne de la grille car conditions particulières

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

    // Bloc de récupération spécifique au milieu de grille

    else if (1 <= indiceC && indiceC <= longueur - 2)
    {
        // Le haut de grille implique également des conditions particulières

        if (indiceL == 0)
        {
            lettre_autour[0] = grille[0][indiceC - 1];
            lettre_autour[1] = grille[0][indiceC + 1];
            lettre_autour[2] = grille[1][indiceC - 1];
            lettre_autour[3] = grille[1][indiceC];
            lettre_autour[4] = grille[1][indiceC + 1];
        }

        // Le bas de grille implique également des conditions particulières

        else if (indiceL == longueur - 1)
        {
            lettre_autour[0] = grille[indiceL-1][indiceC - 1];
            lettre_autour[1] = grille[indiceL-1][indiceC];
            lettre_autour[2] = grille[indiceL-1][indiceC + 1];
            lettre_autour[3] = grille[indiceL][indiceC - 1];
            lettre_autour[4] = grille[indiceL][indiceC + 1];
        }

        // Pour toutes les lettres n'étant pas sur le bord de la grille

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

    /* Définition d'un tableau permettant de récupérer les différentes lettres présentes autour de la lettre étudiée */
    char lettre_autour[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


    for (int k = 0; k < Nb_de_lettres_grille(grille, mot[k], longueur)-1; ++k)
    {
        // Envoie vers une fonction permettant de récupérer les coordonnées de la lettre en cours d'étude
        Coordonnees_lettre(mot[k], longueur, grille, &indiceL, &indiceC);

        int i, nb_lettres_autour;

        /** Début du bloc permettant d'analyser le mot lettre par lettre telles qu'elles ont été entrées par le joueur **/

        for (i = 0; i < strlen(mot) - 1; ++i)   // On répète tant que toutes les lettre n'ont pas été examinées
        {
            // Boucle permettant d'initialiser le tableau de récupération des lettres

            for (int j = 0; j < 9; ++j)
            {
                lettre_autour[j] = NULL;
            }

            // Envoie vers la fonction de récupération des lettres présentes autour de celle étudiée

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

            // Sauvegarde des coordonnées de la lettre précédente ou de la première lettre (dépend de la lettre étudiée)

            indiceLPrecedent = indiceL;
            indiceCPrecedent = indiceC;

            if (Comptage_lettre_tableau(lettre_autour, mot[i+1]) > 0)
            {
                indiceLPrecedent = indiceL;
                indiceCPrecedent = indiceC;

                /** Debut du bloc "Position de la lettre suivante" **/
                /** Comme pour la récupération des coordonées de la lettre précédent la nouvelle,
                 * des conditions particulières sont présentes **/

                // Pour les lettres de la première colonne :

                if (indiceC == 0)
                {
                    // Et de la première ligne :

                    if (indiceL == 0)
                    {
                        // Grâce à ce "switch", nous pouvons récupérer les 3 lettres concernées

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

                    // Lignes du milieu de grille :

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

                    // Dernière ligne :

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

                // Pour la dernière colonne :

                else if (indiceC == longueur - 1)
                {
                    // Première ligne :

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

                    // Milieu de grille

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

                    // Dernière ligne

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

                // Pour le milieu de grille :

                else if (1 <= indiceC && indiceC <= longueur - 2)
                {
                    // Première ligne :

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

                    // Milieu de grille :

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

                    // Milieu de grille :

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

                /* La lettre suivante étant introuvable, on restaure les coordonnées de la lettre précedente.
                 * A ces dernière, on incrémente l'indice de la colonne afin de pouvoir parcourir jusqu'à la
                 * bonne lettre.
                 */

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

    /* Si le nombre de lettres trouvées et vérifiées correspond à la longueur du mot, alors cela signifie que
     * le mot à été trouvé.
     */

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
     * En effet on considère une vitesse max d'un mot par seconde et la longueur max sera celle du mot
     * français le plus long (anticonstitutionellement) soit 25 lettres => 26 caractères */

    int i = 0; // Permet de pouvoir boucler
    int mot_verif = 0;
    char tabmots[temps_limite][26];

    for (int j = 0; j < temps_limite; ++j)
    {
        for (int k = 0; k < 26; ++k)
        {
            tabmots[j][k] = NULL; // Initialisation du tableau permettant de récupérer le mot saisi
        }
    }

    // Tant que le temps imparti n'est pas écouler alors l'utilisateur peut saisir un mot


     //do
     //{
    printf("Saisir un mot : \n");
    scanf("%s", &tabmots[i]); // Le mot taper se trouvera à la i-ème ligne
    printf("%d", strlen(tabmots[i]));
    mot_verif = Traitement_mot(tabmots[i], grille, longueur);
    printf("%d", mot_verif);
    //i = i + 1; // Incrémentation de i pour pouvoir passer au mot suivant
     //}
     /*while (temps_limite > 0); // On répète tant que le temps n'est pas encore arrivé à 0*/


}
