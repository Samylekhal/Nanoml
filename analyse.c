#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "analyse.h"

void comptecaraligne(FILE *source)
{
    char cara = '\0';
    int i;
    int ligne = 1;
    while (cara != EOF)
    {
        cara = fgetc(source);
        i++;
        if (cara == '\n')
        {
            i--;
            printf("%d\n", i);
            i = 0;
            ligne++;
        }
    }
    i--;
    printf("%d\n", i);
    printf("\nCe document possede %d ligne(s)", ligne);
}

int compteligne(FILE *source)
{
    char caractere = '\0';
    int ligne = 1;

    while (caractere != EOF)
    {
        caractere = fgetc(source);
        if (caractere == '\n')
        {
            ligne++;
        }
    }
    return ligne;
};

int comptecaraparligne(FILE *source, int Nligne)
{
    int DEFligne = 1;
    char caractere;

    while (DEFligne < Nligne)
    {
        caractere = fgetc(source);
        if (caractere == EOF)
        {
            printf("Le texte n'a pas autant de ligne");
            return -1;
        }
        if (caractere == '\n')
        {
            DEFligne++;
        }
    }

    int Nbcara = 0;

    // Compter les caractères sur la ligne Nligne
    while (1)
    {
        caractere = fgetc(source);
        if (caractere == EOF || caractere == '\n')
        {
            break;
        }

        Nbcara++;
    }

    return Nbcara;
}

void lire_caractere(t_analyse *ceci)
{
    ceci->cara = fgetc(ceci->monfichier);
    printf("%c", ceci->cara);
}

char debut_ou_fin_balise(t_analyse *ceci)
{
    while (ceci->cara == ' ' || ceci->cara == '<' || ceci->cara == '/' || ceci->cara == '>')
    {
        lire_caractere(ceci);
        switch (ceci->cara)
        {
        case '<':
            lire_caractere(ceci);
            if (ceci->cara == '/')
            {
                return "OPEN_F";
            }
            else
            {
                return "OPEN_O";
            }

            break;
        case '>':
            return "CLOSE";
            break;
        default:
            break;
        }
    }
}

void texte_enrichi(t_analyse *ceci)
{
    document(ceci);
    while (ceci->cara != EOF)
    {
        annexes(ceci);
    }
}
