#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interpretation.h"
#include "arbre.h"

void Interpretation(arbre *document)
{
    arbre *suivi = document;
    if (strcmp(document->balise, "document") == 0)
    {
        document = document->BalSuivante;
        contenu(document);
        while (suivi->BALvoisine != NULL)
        {
            suivi = suivi->BALvoisine;
            Annexe(suivi);
        }
    }
    else
    {
        printf("ERREUR!: la première balise de l'arbre n'est pas un document\n");
        return;
    }
}
void contenu(arbre *nanoarbre)
{
    arbre *archive = nanoarbre;
    printLigne(LONGUEUR, nanoarbre->deep);
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
    printLigne(LONGUEUR, archive->deep);
};
void Annexe(arbre *nanoarbre)
{
    if (strcmp(nanoarbre->balise, "annexe") != 0)
    {
        return;
    }
    printLigne(LONGUEUR, 0);
    remplissage(nanoarbre);
    printf("%s\n", nanoarbre->valeur);
    printLigne(LONGUEUR, 0);
}
void section(arbre *nanoarbre)
{
    printLigne(LONGUEUR - nanoarbre->deep * 2, nanoarbre->deep + 1);

    remplissage(nanoarbre);
    printf("%s", nanoarbre->valeur);
    printf("\n");
    printLigne(LONGUEUR - nanoarbre->deep * 2, nanoarbre->deep + 1);
}

void printLigne(int nb, int colonne)
{

    colonnes(colonne);

    printf("+");
    for (int i = 0; i < nb; i++)
    {
        printf("-");
    }
    printf("+");

    colonnes(colonne);
    printf("\n");
}

void remplissage(arbre *nanoarbre)
{
    colonnes(nanoarbre->deep + 2);
    int longueur = strlen(nanoarbre->valeur);
    int taille = LONGUEUR - (nanoarbre->deep * 2);
    while (longueur < taille)
    {
        strcat(nanoarbre->valeur, " ");
        longueur = strlen(nanoarbre->valeur);
    }
    for (int i = 0; i < nanoarbre->deep; i++)
    {
        strcat(nanoarbre->valeur, "|");
    }
    strcat(nanoarbre->valeur, "|");
};

void colonnes(int nb)
{
    int j = 0;

    if (nb > 0)
    {
        j = 1;
    }

    for (int i = j; i < nb; i++)
    {
        printf("|");
    }
}