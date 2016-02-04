#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    char lettre;
    int fin_de_mot;
    struct noeud **fils;
}

int chercher_mot(struct noeud*dico, char* mot);

int nb_mots(struct noeud *dico);

int inserer_mot(struct noeud *dico, char* mot);

int initialiser(struct noeud **dico);

int supprimer_mot(struct noeud *dico, char* mot);

/*
./tp > file

./tp < file
*/

/*

arbre.h => include dans les deux
arbre.c
main.c

arbre.c -> arbre.o
main.c -> main.o
gcc -o tp_arbre main.c arbre.c

*/


