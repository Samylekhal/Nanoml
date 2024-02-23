#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include <string.h>

arbre *InitialiserArbre(char *bal, char *val)
{
    arbre *nanoarbre = malloc(sizeof(arbre));

    if (nanoarbre == NULL)
    {
        return NULL;
    }

    nanoarbre->balise = malloc(strlen(bal) + 1); // Allouer de la mémoire pour la balise
    if (nanoarbre->balise == NULL)
    {
        free(nanoarbre);
        return NULL;
    }

    nanoarbre->valeur = malloc(strlen(val) + 1); // Allouer de la mémoire pour la balise
    if (nanoarbre->valeur == NULL)
    {
        free(nanoarbre);
        return NULL;
    }
    // Copie la valeur de bal dans balise
    strcpy(nanoarbre->valeur, val);
    strcpy(nanoarbre->balise, bal);
    nanoarbre->BalSuivante = NULL;
    nanoarbre->BALvoisine = NULL;
    return nanoarbre;
};

arbre *Insérerbalisefille(arbre *nanoarbre, char *bal, char *val)
{
    arbre *var = InitialiserArbre(bal, val);
    while (nanoarbre->BalSuivante != NULL)
    {
        nanoarbre = nanoarbre->BalSuivante;
    }
    nanoarbre->BalSuivante = var;
    return var;
}

arbre *InsérerbaliseSoeur(arbre *nanoarbre, char *bal, char *val)
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

void printArbre(arbre *nanoarbre, int profondeur)
{
    // Si le nœud est NULL, retourner
    if (nanoarbre == NULL)
    {
        printf(" NULL");
        return;
    }
    // Afficher la balise du nœud avec la profondeur appropriée
    printf(" %s", nanoarbre->balise);

    // for (int i = 0; i < profondeur; i++)
    // {
    //     print("/t");
    // }

    // Appeler récursivement printArbre pour les voisins et les enfants
    if (nanoarbre->BalSuivante != NULL && nanoarbre->BALvoisine != NULL)
    {
        tab(profondeur);
        printf("descendant de %s :", nanoarbre->balise);
        printArbre(nanoarbre->BalSuivante, profondeur + 1);

        tab(profondeur);
        printf("cadet de %s :", nanoarbre->balise);
        printArbre(nanoarbre->BALvoisine, profondeur);
    }
    else if (nanoarbre->BalSuivante != NULL)
    {
        tab(profondeur);
        printf("descendant de %s :", nanoarbre->balise);
        printArbre(nanoarbre->BalSuivante, profondeur + 1);
    }
    else if (nanoarbre->BALvoisine != NULL)
    {
        tab(profondeur);
        printf("cadet de %s :", nanoarbre->balise);
        printArbre(nanoarbre->BALvoisine, profondeur);
    }
}
void tab(int truc)
{
    printf("\n");
    for (int i = 0; i < truc; i++)
    {
        printf("\t");
    }
}