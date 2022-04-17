#include "fonctions globales.h"
#include "menu.h"
#include "generation grille.h"

int main()
{
    srand(time(0));
    // Utilisation du fichier "menu.c"
    //short choix = Menu(); // Initialisation du choix de l'utilisateur

    // Utilisation du fichier "generation grille.c"
    short longueur = Dimension_grille();

    /** Debut du bloc "Definition de la grille" **/
    char grille[8][8];
    Generation_grille(grille, longueur);
    /** Fin du bloc "Definition de la grille" **/

    Affichage_grille(grille, longueur);

    return 0;
}
