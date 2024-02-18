#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

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

int main()
{
    arbre *A = InitialiserArbre('A', ' ');
    arbre *B = InsérerbaliseSoeur(A, 'B', ' ');
    arbre *C = InsérerbaliseSoeur(B, 'C', ' ');

    arbre *BA = Insérerbalisefille(B, 'F', ' ');
    arbre *AA = Insérerbalisefille(A, 'D', ' ');

    arbre *AB = InsérerbaliseSoeur(AA, 'E', ' ');

    arbre *ABA = Insérerbalisefille(AB, 'G', ' ');

    printf("Avant la suppression :\n");
    printArbre(A);

    SupprimerDescendant(B);

    printf("\n\nAprès la suppression :\n");
    printArbre(A);

    return 0;
}