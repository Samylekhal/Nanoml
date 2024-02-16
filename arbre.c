#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include <string.h>

arbre *InitialiserArbre(char bal, char val)
{
    arbre *nanoarbre = malloc(sizeof(arbre));
    nanoarbre->balise = bal;
    nanoarbre->valeur = val;
    nanoarbre->BalSuivante = NULL;
    nanoarbre->BALvoisine = NULL;
    return nanoarbre;
};

arbre *Insérerbalisefille(arbre *nanoarbre, char bal, char val)
{
    arbre *var = InitialiserArbre(bal, val);
    while (nanoarbre->BalSuivante != NULL)
    {
        nanoarbre = nanoarbre->BalSuivante;
    }
    nanoarbre->BalSuivante = var;
}

arbre *InsérerbaliseSoeur(arbre *nanoarbre, char bal, char val)
{
    arbre *var = InitialiserArbre(bal, val);
    while (nanoarbre->BALvoisine != NULL)
    {
        nanoarbre = nanoarbre->BALvoisine;
    }
    nanoarbre->BALvoisine = var;
};

void *SupprimerCadet(arbre *nanoarbre)
{
    while (nanoarbre->BALvoisine != NULL)
    {
        nanoarbre = nanoarbre->BALvoisine;
    }
    if (nanoarbre->BalSuivante == NULL)
    {
        free(nanoarbre);
    }
    else
    {
        arbre *var = nanoarbre;
        while (nanoarbre->BalSuivante != NULL)
        {
            SupprimerDescendant(nanoarbre);
            free(nanoarbre);
            nanoarbre = var;
        }
    };
};
void SupprimerDescendant(arbre *nanoarbre)
{
    while (nanoarbre->BalSuivante != NULL)
    {
        nanoarbre = nanoarbre->BalSuivante;
    }
    if (nanoarbre->BALvoisine == NULL)
    {
        free(nanoarbre);
    }
    else
    {
        arbre *var = nanoarbre;
        while (nanoarbre->BALvoisine != NULL)
        {
            SupprimerCadet(nanoarbre);
            free(nanoarbre);
            nanoarbre = var;
        }
    }
};

void printArbre(arbre *root, int depth)
{
    // Si le nœud est NULL, retourner
    if (root == NULL)
        return;

    // Afficher la balise du nœud avec la profondeur appropriée
    for (int i = 0; i < depth; i++)
        printf("\t"); // 2 espaces par niveau de profondeur
    printf("%s\n", root->balise);

    // Appeler récursivement printArbre pour les voisins et les enfants
    printArbre(root->BALvoisine, depth);
    printArbre(root->BalSuivante, depth + 1);
}