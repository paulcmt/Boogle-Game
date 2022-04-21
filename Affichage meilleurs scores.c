//
// Created by olivi on 21/04/2022.
//
#include <stdio.h>

void Affichage_meilleurs_scores(tabscore[10]){

    int i=0; // Pour établir la boucle

    // Boucle pour afficher les 10 premiers meilleurs scores enregistrés précédemment
    // dans le tableau à 1 dimension tabscore[]

    for (i=0;i<10;i=i+1){
        printf("%d/ %d",i+1, tabscore[i]);
    }
}
