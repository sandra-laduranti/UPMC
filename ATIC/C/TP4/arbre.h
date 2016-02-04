#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noeud{
    char lettre;
    int fin_de_mot;
    struct noeud **fils;
};

typedef struct noeud noeud;

int chercher_mot(struct noeud*dico, char* mot);

int nb_mots(struct noeud *dico);

noeud *ajouternoeud(noeud *racine, char lettre, int fin_de_mot);

void ajouter_mot(struct noeud *dico, char* mot);

noeud *initialiser();

int	suppr_mot(noeud *racine, char *mot);

int supprimer_mot(struct noeud *dico, char* mot);

//detruire(struct *noeud dico);
