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
    return var;
}

arbre *InsérerbaliseSoeur(arbre *nanoarbre, char bal, char val)
{
    arbre *var = InitialiserArbre(bal, val);
    while (nanoarbre->BALvoisine != NULL)
    {
        nanoarbre = nanoarbre->BALvoisine;
    }
    nanoarbre->BALvoisine = var;
    return var;
};

void SupprimerCadet(arbre *nanoarbre)
{
    arbre *precedant = nanoarbre;
    arbre *recup = nanoarbre;
    int i = 0;
    while (nanoarbre->BALvoisine != NULL)
    {
        nanoarbre = nanoarbre->BALvoisine;
        if (i >= 1)
        {
            precedant = precedant->BALvoisine;
        }
        i++;
    }
    if (nanoarbre->BalSuivante == NULL)
    {
        free(nanoarbre);
        precedant->BALvoisine = NULL;
    }
    else
    {
        arbre *var = nanoarbre;
        while (nanoarbre->BalSuivante != NULL)
        {
            SupprimerDescendant(nanoarbre->BalSuivante);
            free(nanoarbre->BalSuivante);
            nanoarbre->BalSuivante = NULL; // Assurez-vous de supprimer les liens vers les descendants
        }
        free(var); // Supprime le dernier nœud
    }
    if (recup->BalSuivante == NULL && recup->BALvoisine == NULL)
    {
        return;
    }
}

void SupprimerDescendant(arbre *nanoarbre)
{
    arbre *precedant = nanoarbre;
    arbre *recup = nanoarbre;
    int i = 0;
    while (nanoarbre->BalSuivante != NULL)
    {
        nanoarbre = nanoarbre->BalSuivante;
        if (i >= 1)
        {
            precedant = precedant->BalSuivante;
        }
        i++;
    }
    if (nanoarbre->BALvoisine == NULL)
    {
        free(nanoarbre);
        precedant->BalSuivante = NULL;
    }
    else
    {
        arbre *var = nanoarbre;
        while (nanoarbre->BALvoisine != NULL)
        {
            SupprimerCadet(nanoarbre->BALvoisine);
            free(nanoarbre->BALvoisine);
            nanoarbre->BALvoisine = NULL; // Assurez-vous de supprimer les liens vers les voisins
        }
        free(var); // Supprime le dernier nœud
        if (recup->BalSuivante == NULL && recup->BALvoisine == NULL)
        {
            return;
        }
    }
}

void printArbre(arbre *root)
{
    // Si le nœud est NULL, retourner
    if (root == NULL)
    {
        printf(" NULL");
        return;
    }
    // Afficher la balise du nœud avec la profondeur appropriée
    printf(" %c\n", root->balise);

    // Appeler récursivement printArbre pour les voisins et les enfants

    printf("descendant de %c :", root->balise);
    printArbre(root->BalSuivante);
    printf("\ncadet de %c :", root->balise);
    printArbre(root->BALvoisine);
}