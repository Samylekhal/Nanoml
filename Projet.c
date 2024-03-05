#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "analyse.h"
#include "Interpretation.h"

arbre *source1()
{
    arbre *DOC = InitialiserArbre("document", "");
    arbre *section = Insérerbalisefille(DOC, "section", "Bonjour le monde");
    arbre *annexe = InsérerbaliseSoeur(DOC, "annexe", "Auteur : Weinberg Benjamin Date : 23/01/2024");
    return DOC;
}

int main()
{
    arbre *S1 = source1();

    // arbre *C = InsérerbaliseSoeur(B, "annexe", "ssssssssafgz");
    // arbre *BA = Insérerbalisefille(B, "item", "qdsgefef");
    // arbre *AA = Insérerbalisefille(A, "titre", "vvqdfdq");
    // arbre *AB = InsérerbaliseSoeur(AA, "item", "qscrggs");
    // arbre *ABA = Insérerbalisefille(AB, "titre", "qdggzzggz");
    //  printf("Avant la suppression :\n");
    // printArbre(A, 0);
    // SupprimerDescendant(B);
    // printf("\n\nAprès la suppression :\n");
    // printArbre(A);
    // FILE *fichier = fopen("source4.txt", "r");
    // comptecaraligne(fichier);
    Interpretation(S1);
    return 0;
}