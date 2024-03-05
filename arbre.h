#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nanoarbre
{
    char *balise;                  // indique le type de balise du fichier texte (document,titre,ect...)
    char *valeur;                  // Texte si jamais il y'en a dans cette balise
    struct nanoarbre *BALvoisine;  // reidrige vers la balise situer sur le même plan (ex: document redirige vers annexe)
    struct nanoarbre *BalSuivante; // redirige vers la première balise se trouvant à l'intérieur de celle-ci
    int deep;
} arbre;

arbre *InitialiserArbre(char *bal, char *val);
arbre *Insérerbalisefille(arbre *nanoarbre, char *bal, char *val);
arbre *InsérerbaliseSoeur(arbre *nanoarbre, char *bal, char *val);
void SupprimerDescendant(arbre *nanoarbre);
void SupprimerCadet(arbre *nanoarbre);
void printArbre(arbre *nanoarbre, int profondeur);
void tab(int truc);

#endif