#include "fonctions globales.h" // Bibliothèque des fonctions nécessaires pour l'affichage ou les tests
#include "menu.h" // Bibliothèque pour afficher le menu
#include "generation grille.h" // Bibiliothèque pour générer la grille
#include "score.h" // Bibliothèque pour calculer et afficher les scores
#include "mots.h" // Bibliothèque pour saisir les mots et faire la vérification de la langue française

int main()
{
    srand(time(NULL));

    // Utilisation du fichier "menu.c"
    short choix = Menu(); // Initialisation du choix de l'utilisateur
    short longueur;

    //Conséquence du choix
    switch (choix)
    {
        case 1 : // Lancement de la partie

            // Utilisation du fichier "generation grille.c"
            longueur = Dimension_grille(); // Demande dimension de la grille

            /** Debut du bloc "Definition de la grille" **/
            char grille[8][8];
            Generation_grille(grille, longueur);
            /** Fin du bloc "Definition de la grille" **/

            short temps_limite = Temps_de_la_partie();

            //Saisie_de_mots(temps_limite);
            Affichage_grille(grille, longueur);

            break;

        case 2 : // Calcul + affichage des scores

            printf("\n WALL OF FAME C-BOGGLE \n");
            printf("-----------------------");
            /* Appel la fonction affichage des scores */
            //Affichage_meilleurs_scores(tabscore);

            break;
    }

    return 0;
}
