#include "stdio.h"
#include "stdlib.h"
#include "menu.h"
#include "demarrage partie.h"

int main()
{
    // Utilisation du fichier "menu.c"
    short choix = Menu(); // Initialisation du choix de l'utilisateur

    // Utilisation du fichier "demarrage partie.c"
    short longueur = Dimension_grille();

    return 0;
}
