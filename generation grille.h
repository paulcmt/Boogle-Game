#ifndef PROJET_BOGGLE_DEMARRAGE_PARTIE_H
#define PROJET_BOGGLE_DEMARRAGE_PARTIE_H

#endif //PROJET_BOGGLE_DEMARRAGE_PARTIE_H

int Dimension_grille();
char Generation_lettre_aleatoire();
void Generation_sous_carre3x3(char sous_carre3x3[9]);
void Lettre_commune(char sous_carre3x3[9]);
void Lettre_commune2_0(char sous_carre3x3[9]);
void Assignation_sous_carre_vers_grille(char grille[8][8], char sous_carre3x3[9]);
void Decalage_a_droite(char grille[8][8], char sous_carre3x3[9], short longueur);
void Generation_grille(char grille[8][8], short longueur);