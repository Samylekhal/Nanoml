#ifndef INTERPRETATION_H
#define INTERPRETATION_H
#define LONGUEUR 50 // nombre de caractère max horizontal pour le fichier txt

#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

void Interpretation(arbre *nanoarbre);
void contenu(arbre *nanoarbre);
void Annexe(arbre *nanoarbre);
void section(arbre *nanoarbre);
void titre(arbre *nanoarbre);
void mot_enrichi(arbre *nanoarbre);
void liste(arbre *nanoarbre);
void printLigne(int nb, int colonne);
void remplissage(arbre *nanoarbre);
void colonnes(int nb);

#endif
