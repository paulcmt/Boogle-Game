#include "mots.h"
#include "fonctions globales.h"

/** Fonction retournant le nombre de fois qu'une lettre est présente dans la grille **/
int Nb_de_lettres_grille(char grille[8][8], char lettre_a_compter, int longueur) // On donne la grille, la lettre à chercher et la longueur de la grille
{
    int compteur = 0; // Compteur pour savoir combien de fois la lettre est présente dans la grille

    lettre_a_compter = toupper(lettre_a_compter); // Passage en majuscule obligatoire pour comparer avec les lettres de la grille

    for (int i = 0; i < longueur; ++i)  // Boucle permettant de parcourir la grille sur les lignes
    {
        for (int j = 0; j < longueur; ++j) // Boucle permettant de parcourir la grille sur les colonnes
        {
            if (grille[i][j] == lettre_a_compter) // Verification lettre à comparer est égale à la lettre actuelle de la grille
            {
                compteur++; // Si lettre à comparer est égale à la lettre actuelle de la grille on incrémente le compteur de 1
            }
        }
    }

    return compteur; // On retourne la valeur du compteur (un entier)
}

/** Fonction permettant de donner les coordonnées d'une lettre dans la grille à partir d'une position donnée **/
void Coordonnees_lettre(char lettre, int longueur, char grille[8][8], int *indiceL, int *indiceC) // On donne la lettre de laquelle on veut les coordonnées, la longueur de la grille, la grille, deux pointeurs pointant vers la position à partir de laquelle ont veyr les coordonnées de la lettre voulue
{

    *indiceC = *indiceC - 1; // On décremente la lettre d'une unité car le do while l'augmentera d'une unité lors du premier passage
    int indiceCRetenu = 0; // Sauvegarde l'indice colonne car il est modifié et on veut le récupérer par la suite

    lettre = toupper(lettre); // Passage en majuscule obligatoire pour comparer la lettre dans la grille

    do // Boucle permettant de parcourir la grille à la recherche de la lettre
    {
        do // Boucle permettant de parcourir la grille de gauche à droite sur une même ligne
        {
            *indiceC = *indiceC + 1; // Passage à la lettre suivante (à droite)
        }
        while (*indiceC < longueur - 1 && lettre != grille[*indiceL][*indiceC]); // Si l'indice colonne dépasse la grille ou que la lettre a été trouvé, on sors de la boucle

        // Les instructions suivantes vont être éxécutées même si la lettre a été trouvé mais cela n'a aucun impact sur les résultats

        *indiceL = *indiceL + 1; // Passage à la ligne suivante
        indiceCRetenu = *indiceC; // Récupération de l'indice colonne de la lettre si trouvée ou de la dernière colonne
        *indiceC = -1; // On réinitialise l'indice colonne pour continuer à parcourir la grille si nécessaire (si lettre non trouvée)
    }
    while (*indiceL < longueur && lettre != grille[*indiceL - 1][indiceCRetenu]); // Si on dépasse les dimensions de la grille ou si la lettre a été trouvé, on sors de la boucle

    // Résultats
    *indiceL = *indiceL - 1; // On décremente l'indice de ligne car on l'a augmenté d'un au dessus (même si la lettre a été trouvé)
    *indiceC = indiceCRetenu; // On récupère l'indice colonne qu'on avait sauvegardé précedemment
}

void Obtention_lettres_autour(char lettre_autour[8], int indiceC, int indiceL, char grille[8][8], int longueur)
{
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
    int indiceL = 0,
        indiceC = 0,
        indiceLRetenu = 0,
        indiceCRetenu = 0,
        nb_lettres_verifiees = 0,
        longueur_du_mot = strlen(mot) - 1;

    /** Début du bloc de traitement du mot entré **/

    // Définition d'un tableau permettant de récupérer les différentes lettres présentes autour de la lettre étudiée
    char lettre_autour[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

    // Va vérifier c fois la première lettre du mot présent dans la grille
    for (int c = 0; c < Nb_de_lettres_grille(grille, mot[0], longueur); c = c + 1)
    {
        // Envoie vers une fonction permettant de récupérer les coordonnées de la lettre en cours d'étude
        Coordonnees_lettre(mot[c], longueur, grille, &indiceL, &indiceC);
        indiceCRetenu = indiceC;
        indiceLRetenu = indiceL;

        if (indiceC == longueur - 1 && indiceL == longueur - 1 && toupper(mot[c]) != grille[indiceL][indiceC])
        {
            return 0;
        }

        int d, nb_lettres_autour = 0;

        /** Début du bloc permettant d'analyser le mot lettre par lettre telles qu'elles ont été entrées par le joueur **/
        for (d = 0; d < longueur_du_mot; d = d + 1) // On répète tant que toutes les lettre n'ont pas été examinées
        {
            // Boucle permettant d'initialiser le tableau de récupération des lettres
            for (int e = 0; e < 8; e = e + 1)
            {
                lettre_autour[e] = NULL;
            }

            // Envoie vers la fonction de récupération des lettres présentes autour de celle étudiée
            Obtention_lettres_autour(lettre_autour, indiceC, indiceL, grille, longueur);

            /** Début du bloc "Calcul nombre lettres autoures" **/
            nb_lettres_autour = -1;

            int j = -1;

            do
            {
                nb_lettres_autour ++;
                j++;
            }
            while (lettre_autour[j] != NULL);
            /** Fin du bloc "Calcul nombre lettres autoures" **/

            // Condition pour faire la vérification de la présence de la lettre suivante dans les lettres autours
            if (Comptage_lettre_tableau(lettre_autour, mot[d+1]) > 0)
            {
                /* Debut du bloc "Position de la lettre suivante"
                 Comme pour la récupération des coordonées de la lettre précédent la nouvelle,
                 des conditions particulières sont présentes */

                // Pour les lettres de la première colonne :
                if (indiceC == 0)
                {
                    // Et de la première ligne :
                    if (indiceL == 0)
                    {
                        // Grâce à ce "switch", nous pouvons récupérer les 3 lettres concernées
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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
                        switch (Position_lettre_tab_lettre_autour(lettre_autour, mot[d+1], nb_lettres_autour))
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

                //printf("Lettre suivante trouvée\n");
                nb_lettres_verifiees = nb_lettres_verifiees + 1;
            }

            else if (d == 0)
            {
                c = c - 1;
                nb_lettres_verifiees = 0;
                //printf("Lettre suivante introuvable\n");

                /* La lettre suivante étant introuvable, on restaure les coordonnées de la lettre précedente.
                 * A ces dernière, on incrémente l'indice de la colonne afin de pouvoir parcourir jusqu'à la
                 * bonne lettre.
                 */

                if (indiceC == longueur - 1)
                {
                    indiceL = indiceL + 1;
                    indiceC = 0;
                    break;
                }

                else
                {
                    indiceC = indiceC + 1;
                    break;
                }
            }

            else
            {
                c = c - 1;
                nb_lettres_verifiees = 0;
                //printf("Lettre suivante introuvable\n");

                /* La lettre suivante étant introuvable, on restaure les coordonnées de la lettre précedente.
                 * A ces dernière, on incrémente l'indice de la colonne afin de pouvoir parcourir jusqu'à la
                 * bonne lettre.
                 */

                if (indiceC == longueur - 1 || indiceLRetenu == longueur - 1)
                {
                    indiceL = indiceLRetenu + 1;
                    indiceC = 0;
                    d = d - 1;
                    break;
                }
                else
                {
                    indiceC = indiceCRetenu + 1;
                    indiceL = indiceLRetenu;
                    d = d - 1;
                    break;
                }
            }

        }

        // Condition pour faire la vérification de la dernière lettre
        if (nb_lettres_verifiees == longueur_du_mot && Comptage_lettre_tableau(lettre_autour, mot[d]) == 0)
        {
            return 0;
        }

        else if (nb_lettres_verifiees == longueur_du_mot && Comptage_lettre_tableau(lettre_autour, mot[d]) > 0)
        {
            return 1;
        }

    }

    /* Si le nombre de lettres trouvées et vérifiées correspond à la longueur du mot, alors cela signifie que
     * le mot à été trouvé.
     */

    return 0;

    /** Fin du bloc de traitement du mot entré **/
}

int Test(char mot[], char grille[8][8], int longueur)
{
    return 1;
}

int Verification_francais(char mot_a_comparer[])
{
    char mot_fr[26];
    FILE *fichier = NULL;
    fichier = fopen("../liste_mot1.txt", "r");

    if (fichier != NULL)
    {
        for (int e = 0; e < 165000; ++e)
        {
            fgets(mot_fr, 25, fichier);

            for (int i = 0; i < 26; ++i)
            {
                if (mot_fr[i] == '\n')
                {
                    mot_fr[i] = NULL;
                }
                if (mot_fr[i] == '\r')
                {
                    mot_fr[i] = NULL;
                }
            }

            if (strcmp(mot_fr, mot_a_comparer) == 0)
            {
                return 1;
            }

        }
        fclose(fichier);
    }

    else
    {
        printf("Echec");
    }

    fichier = NULL;
    fichier = fopen("../liste_mot2.txt", "r");

    if (fichier != NULL)
    {
        for (int e = 0; e < 171533; ++e)
        {
            fgets(mot_fr, 25, fichier);

            for (int i = 0; i < 26; ++i)
            {
                if (mot_fr[i] == '\n')
                {
                    mot_fr[i] = NULL;
                }
                if (mot_fr[i] == '\r')
                {
                    mot_fr[i] = NULL;
                }
            }

            if (strcmp(mot_fr, mot_a_comparer) == 0)
            {
                return 1;
            }
        }

        fclose(fichier);
    }
    else
    {
        printf("Echec");
    }

    return 0;
}

void Saisie_de_mots(int temps_limite, char grille[8][8], int longueur, char tabmots[][26])
{

    for (int j = 0; j < temps_limite * 2; ++j) // Boucle permettant l'initialisation du tableau pour récupérer le mot saisi
    {
        for (int k = 0; k < 26; ++k)
        {
            tabmots[j][k] = NULL;
        }
    }

    /** Début du bloc "Déclaration des variables nécessaires pour la fonction" **/
    int i = 0,
        mot_verif = 0,
        mot_dans_liste = 0,
        nb_de_mots_valide = 0,
        mot_deja_existant = 0;

    double temps = 0;
    clock_t t1 = 0, t2 = 0;
    /** Fin du bloc "Déclaration des variables nécessaires pour la fonction" **/

    do // Tant que le temps imparti n'est pas écouler alors l'utilisateur peut saisir un mot
    {
        t1 = clock(); // Première mesure du temps

        /** Début du bloc "Intialisation des variables de validation pour un mot" **/
        mot_verif = 0;
        mot_dans_liste = 0;
        mot_deja_existant = 0;
        /** Fin du bloc "Intialisation des variables de validation pour un mot" **/

        printf("---------------------------\n");
        printf("Nombre de mots valides : %hd\n", nb_de_mots_valide); // Affiche le nombre de mots validés

        Affichage_grille(grille, longueur); // Affichage de la grille

        printf("Saisir un mot : \n"); // Saisie du mot
        scanf(" %s", &tabmots[i]); // Le mot taper se trouvera à la i-ème ligne

        /** Début du bloc "Vérification du mot existant" **/
        for (int h = 0; h < i; ++h)
        {
            if (strcmp(tabmots[i], tabmots[h]) == 0) // Mot dejà saisi
            {
                printf("Mot deja saisi\n");
                mot_deja_existant = 1;
            }
        }
        /** Fin du bloc "Vérification du mot existant" **/

        /** Début du bloc "Vérification mot dans la grille et dans la liste" **/
        if (mot_deja_existant == 0)
        {
            mot_verif = Traitement_mot(tabmots[i], grille, longueur); // Vérification mot dans la grille

            mot_dans_liste = Verification_francais(tabmots[i]); // Vérification mot français

            if (mot_dans_liste == 1 && mot_verif == 1) // Mot présent dans la grille et dans la liste
            {
                printf("Le mot est valide\n");
                nb_de_mots_valide = nb_de_mots_valide + 1; // Incrémentation du nombre de mots valide
            }

            else
            {
                printf("Le mot est invalide\n");

                // Reset de la place occuppé par le mot saisi car non valide
                for (int j = 0; j < 26; ++j)
                {
                    tabmots[i][j] = NULL;
                }

                i --; // Permet de se resituer à la bonne position pour saisir un mot
            }

            i++; // Sert à incrémenter la ligne dans le tableau de saisi des mots
        }
        /** Fin du bloc "Vérification mot dans la grille et dans la liste" **/

        t2 = clock(); // Enregistrement date fin, deuxième mesure de temps
        temps = temps + (double) (t2 - t1) / (double) CLOCKS_PER_SEC; // Calcul de la différence + ajout au temps déjà présent

    } while (temps_limite > temps); // Vérification que le temps pris par l'utilisateur n'a pas dépassé le temps fixé au début

    printf("---------------------------");
    printf("\nFin de la partie !");

}
