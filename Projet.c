#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "analyse.h"

int main()
{
    arbre *A = InitialiserArbre("document", "dgndgsnh");

    arbre *B = InsérerbaliseSoeur(A, "annexe", "     ");
    arbre *C = InsérerbaliseSoeur(B, "annexe", "ssssssssafgz");

    arbre *BA = Insérerbalisefille(B, "item", "qdsgefef");
    arbre *AA = Insérerbalisefille(A, "titre", "vvqdfdq");

    arbre *AB = InsérerbaliseSoeur(AA, "item", "qscrggs");

    arbre *ABA = Insérerbalisefille(AB, "titre", "qdggzzggz");

    //  printf("Avant la suppression :\n");
    printArbre(A, 0);

    // SupprimerDescendant(B);

    // printf("\n\nAprès la suppression :\n");

    // printArbre(A);

    // FILE *fichier = fopen("source4.txt", "r");

    // comptecaraligne(fichier);

    return 0;
}