#include "fonctions globales.h"
#include "menu.h"
#include "generation grille.h"

int main()
{
    // Utilisation du fichier "menu.c"
    //short choix = Menu(); // Initialisation du choix de l'utilisateur

    // Utilisation du fichier "demarrage partie.c"
    short longueur = 5;//Dimension_grille();

    // Debut du bloc "Definition de la grille"
    char grille[8][8];

    Generation_grille(grille, longueur);

    return 0;
}
