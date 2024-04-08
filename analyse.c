#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "analyse.h"

arbre *nanoarbre;

void lire_caractère(t_analyse *ceci)
{
    if (ceci->cara != EOF)
    {
        ceci->cara = fgetc(ceci->monfichier);
        printf("%c", ceci->cara);
    }
    return;
}
void passe_caractère(t_analyse *ceci, char cara)
{
    while (ceci->cara != cara || ceci->cara == EOF)
    {
        lire_caractère(ceci);
    }
    return;
}

void anti_vide(t_analyse *ceci)
{
    while (ceci->cara == ' ' || ceci->cara == '\n' || ceci->cara == '\t' || ceci->cara == '\r')
    {
        lire_caractère(ceci);
    }
    return;
}

void amorcer(char *nom_fichier, t_analyse *ceci){
    ceci->cara = '\0';
    ceci->monfichier = fopen(nom_fichier, "r");
    A_texte_enrichi(ceci);
    return;
}
void A_texte_enrichi(t_analyse *ceci)
{
    A_document(ceci);
    A_annexe(ceci);
    // while (ceci->cara != EOF)
    // {
    //     A_annexe(ceci);
    // }
    printf("\nAnalyse terminée\n\nPrint de l'arbre : \n");
    ceci->analyse = nanoarbre;
    printArbre(ceci->analyse, 0);
    fflush(stdout);
    return;
    
}


void A_document(t_analyse *ceci)
{
    passe_caractère(ceci, '>');
    lire_caractère(ceci);
    anti_vide(ceci);
    nanoarbre = InitialiserArbre("document", "");
    A_contenue(ceci);
    return;
}

void A_contenue(t_analyse *ceci){
    if (ceci->cara == '<')
    {
        lire_caractère(ceci);
        if (ceci->cara == '/')
        {

            lire_caractère(ceci);
            if (ceci->cara == 'd')
            {
                passe_caractère(ceci, '>');
                passe_caractère(ceci, '<');
                while (strcmp(nanoarbre->balise, "document") != 0)
                {
                    nanoarbre = nanoarbre->precedent;
                }
                return;
            }else if (ceci->cara == 'a')
            {
                passe_caractère(ceci, '>');
                lire_caractère(ceci);
                anti_vide(ceci);
                
                return;
            }
            else
            {
                passe_caractère(ceci, '>');
                lire_caractère(ceci);
                anti_vide(ceci);
                A_contenue(ceci);
            }
        }
        switch (ceci->cara)
        {
            case ('s'):
                passe_caractère(ceci, '>');
                lire_caractère(ceci);
                anti_vide(ceci);
                A_section(ceci);
            break;
            case ('t'):
                passe_caractère(ceci, '>');
                A_titre(ceci);
                break;
            case ('l'):
                passe_caractère(ceci, '>');
                lire_caractère(ceci);
                A_liste(ceci); //
                break;
            case ('b'):
                nanoarbre->valeur = strcat(nanoarbre->valeur, "\n");
                passe_caractère(ceci, '>');
                lire_caractère(ceci);
                anti_vide(ceci);
                A_contenue(ceci);
                break;
            case('i'):
                passe_caractère(ceci, '>');
                lire_caractère(ceci);
                passe_caractère(ceci, '<');
                A_contenue(ceci);
                break;

            default:
                break;
        }
    }else
    {
        anti_vide(ceci);
        A_mot_enrichi(ceci);

    }
    return;
}
void A_section(t_analyse *ceci){ 
    
    arbre *section;
    if (strcmp(nanoarbre->balise, "document") == 0)
    {
        section = Insérerbalisefille(nanoarbre, "section", "");
    }else{
        section = InsérerbaliseSoeur(nanoarbre, "section", "");
    }

    nanoarbre = section;

    if (ceci->cara != '<')
    {
        A_mot_enrichi(ceci);
    }
    A_contenue(ceci);
    return;
}

void A_titre(t_analyse *ceci){
    lire_caractère (ceci);
    anti_vide(ceci);
    arbre *titre = Insérerbalisefille(nanoarbre, "titre", "");
    nanoarbre = titre;
    A_mot_enrichi(ceci);
    return;
}
void A_liste(t_analyse *ceci){
    anti_vide(ceci);
    passe_caractère(ceci, '<');
    lire_caractère(ceci);
    lire_caractère(ceci);
    while (ceci->cara != 'l')
    {
        A_item(ceci);
    }
    passe_caractère(ceci, '>');
    lire_caractère(ceci);
    anti_vide(ceci);
    A_contenue(ceci);
    return;
}

void A_item(t_analyse *ceci){
    passe_caractère(ceci, '>');
    passe_caractère(ceci, '/');
    passe_caractère(ceci, '>');
    lire_caractère(ceci);
    anti_vide(ceci);
    lire_caractère(ceci);
    lire_caractère(ceci);
    return;
}

void A_mot_enrichi(t_analyse *ceci){
    valeurBalise(ceci, nanoarbre, '<');
    if (strcmp(nanoarbre->balise, "titre") == 0 && strcmp(nanoarbre->precedent->balise,"section") == 0 )
    {
        nanoarbre = nanoarbre->precedent;
    }
    if (ceci->cara != EOF) {
        A_contenue(ceci);
    }
    return;
}

void A_annexe(t_analyse *ceci){
    arbre *annexe1 = InsérerbaliseSoeur(nanoarbre, "annexe", "");
    nanoarbre = annexe1;
    passe_caractère(ceci, '>');
    lire_caractère(ceci);
    anti_vide(ceci);
    A_contenue(ceci);
    while (strcmp(nanoarbre->balise, "document") != 0)
    {
        nanoarbre = nanoarbre->precedent;
    }
    return;
}

// fonctions de débuggage (j'étais énervé ce jour là)
void tm(){
    printf("tamer");
    return;
}

void CC(){
    printf("CHIPPICHAPPA");
    return;
}


void valeurBalise(t_analyse *ceci, arbre *nanoarbre, char cela){ 
    char buffer[1024];
    strcpy(buffer, nanoarbre->valeur); // Copy the value of nanoarbre->valeur to buffer
    int i = 0;
    anti_vide(ceci);
    while (ceci->cara != cela && ceci->cara != EOF)
    {

        if (ceci->cara != cela && ceci->cara != EOF)
        {
            char temp[2] = {ceci->cara, '\0'}; // Crée une chaîne temporaire avec le caractère actuel
            strcat(buffer, temp); // Ajoute la chaîne temporaire à buffer

        }
        lire_caractère(ceci);
        i++;
    }
    buffer[i+1] = '\0'; // Ajoute un caractère de fin de chaîne à buffer
    strcpy(nanoarbre->valeur, buffer);
    return;
}


