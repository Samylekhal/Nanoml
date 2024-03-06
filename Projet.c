#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "analyse.h"
#include "Interpretation.h"

arbre *source1()
{
    arbre *DOC = InitialiserArbre("document", "");
    arbre *section = Insérerbalisefille(DOC, "section", "Bonjour le monde");
    arbre *annexe = InsérerbaliseSoeur(DOC, "annexe", "Auteur : Weinberg Benjamin Date : 23/01/2024");
    return DOC;
}

arbre *source2()
{
    arbre *document = InitialiserArbre("document", "");
    arbre *section = Insérerbalisefille(document, "section", "");
    arbre *titre = Insérerbalisefille(section, "Titre", "Sujet de projet Nanoml");
    arbre *annexe = InsérerbaliseSoeur(document, "annexe", "Auteur : Weinberg Benjamin \nDate : 23/01/2024");
    arbre *annexe2 = InsérerbaliseSoeur(annexe, "annexe", "test1");
    arbre *annexe3 = InsérerbaliseSoeur(annexe2, "annexe", "test2");
    arbre *annexe4 = InsérerbaliseSoeur(annexe3, "annexe", "test3");
    arbre *annexe5 = InsérerbaliseSoeur(annexe4, "annexe", "test4");
    arbre *annexe6 = InsérerbaliseSoeur(annexe5, "annexe", "test5");
    arbre *annexe7 = InsérerbaliseSoeur(annexe6, "annexe", "test6");
    return document;
}

int main()
{
    // arbre *S1 = source1();
    arbre *S2 = source2();

    // FILE *fichier = fopen("source4.txt", "r");
    // comptecaraligne(fichier);
    Interpretation(S2);
    return 0;
}