#include "fonctions globales.h"

void Initialisation_tableau(char Tabl[])
{
    for (int i = 0; i < strlen(Tabl); ++i)
    {
        Tabl[i] = NULL;
    }
}