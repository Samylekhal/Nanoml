#ifndef ANALYSE_H
#define ANALYSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct analyse
{
    FILE *monfichier;
    char cara;
    arbre *analyse;
} t_analyse;

void comptecaraligne(FILE *source);
int compteligne(FILE *source);
int comptecaraparligne(FILE *source, int Nligne);
void amorcer(char* nom_fichier,t_analyse *ceci);
void anti_vide(t_analyse *ceci);

void A_texte_enrichi(t_analyse *ceci);
void A_document(t_analyse *ceci);
void A_annexe(t_analyse *ceci);
void A_contenue(t_analyse *ceci);

void A_section(t_analyse *ceci);
void A_titre(t_analyse *ceci);
void A_liste(t_analyse *ceci);
void A_item(t_analyse *ceci);
void A_mot_enrichi(t_analyse *ceci);

// indique le présence de l'ouverture ou de la fermeture des balises
void est_balise(t_analyse *ceci);
void valeurBalise(t_analyse *ceci,arbre *nanoarbre,char cela);

void tbm();
#endif
