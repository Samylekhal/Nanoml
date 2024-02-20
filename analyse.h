#ifndef ANALYSE_H
#define ANALYSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct analyse
{
    FILE *monfichier;
    char cara;
} t_analyse;

void comptecaraligne(FILE *source);

int compteligne(FILE *source);

int comptecaraparligne(FILE *source, int Nligne);

void texte_enrichi(t_analyse *ceci);
void document(t_analyse *ceci);
void annexes(t_analyse *ceci);

// indique le présence de l'ouverture ou de la fermeture des balises
char debut_ou_fin_balise(t_analyse *ceci);
#endif
