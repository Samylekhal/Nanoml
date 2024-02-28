#ifndef INTERPRETATION_H
#define INTERPRETATION_H

#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

void Interpretation(arbre *nanoarbre);
void Document(arbre *nanoarbre);
void Annexe(arbre *nanoarbre);
void section(arbre *nanoarbre);
void titre(arbre *nanoarbre);
void mot_enrichi(arbre *nanoarbre);
void liste(arbre *nanoarbre);
void printLigne(int nb);

#endif
