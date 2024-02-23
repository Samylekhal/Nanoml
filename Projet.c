#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "analyse.h"

int main()
{
    arbre *A = InitialiserArbre('A', ' ');

    arbre *B = InsérerbaliseSoeur(A, 'B', ' ');
    arbre *C = InsérerbaliseSoeur(B, 'C', ' ');

    arbre *BA = Insérerbalisefille(B, 'F', ' ');
    arbre *AA = Insérerbalisefille(A, 'D', ' ');

    arbre *AB = InsérerbaliseSoeur(AA, 'E', ' ');

    arbre *ABA = Insérerbalisefille(AB, 'G', ' ');

    printf("Avant la suppression :\n");
    printArbre(A);

    SupprimerDescendant(B);

    printf("\n\nAprès la suppression :\n");

    printArbre(A);

    // FILE *fichier = fopen("source4.txt", "r");

    // comptecaraligne(fichier);

    return 0;
}