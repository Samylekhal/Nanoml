#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interpretation.h"
#include "arbre.h"

void Interpretation(arbre *document)
{
    arbre *suivi = document;
    Document(document);
    while (suivi->BALvoisine != NULL)
    {
        suivi = suivi->BALvoisine;
        Annexe(suivi);
    }
}
void Document(arbre *nanoarbre)
{
    printLigne(50);
    nanoarbre = nanoarbre->BalSuivante;
    if (strcmp(nanoarbre->balise, "section") == 0)
    {
        section(nanoarbre);
    }
    else if (strcmp(nanoarbre->balise, "titre") == 0)
    {
        // titre(nanoarbre);
    }
    else if (strcmp(nanoarbre->balise, "mot enrichi") == 0)
    {
        //   mot_enrichi(nanoarbre);
    }
    else if (strcmp(nanoarbre->balise, "liste") == 0)
    {
        // liste(nanoarbre);
    }
    printLigne(50);
};
void Annexe(arbre *nanoarbre)
{
    if (strcmp(nanoarbre->balise, "annexe") != 0)
    {
        return;
    }
    printLigne(50);
    printf("|%s |\n", nanoarbre->valeur);
    printLigne(50);
}
void section(arbre *nanoarbre)
{
    printf("%s\n", nanoarbre->valeur);
}

void printLigne(int nb)
{
    printf("+");
    for (int i = 0; i < nb; i++)
    {
        printf("-");
    }
    printf("+\n");
}
