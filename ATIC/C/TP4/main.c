#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
/* supprimer_mot + detruire_arbre */
int main()
{
    int i;
    noeud *dico;
    noeud* test;
    noeud *root;

    dico=initialiser();
    ajouter_mot(dico, "petitesirene");
    test=dico;
    root=dico;
    for(i=0;i<12;i++){
    printf("%c", dico->fils[0]->lettre);
    dico=dico->fils[0];
    }
    printf("\n");
    dico=test;
    ajouter_mot(dico, "flipperledauphin");
    printf("%c", dico->fils[1]->lettre);
    dico = dico->fils[1];
    for(i=0;i<15;i++){
    printf("%c", dico->fils[0]->lettre);
    dico=dico->fils[0];
    }
    printf("\n\nflipper %d\n",chercher_mot(root,"flipperledauphin"));
    printf("lolol %d\n", chercher_mot(test, "lolol"));
    suppr_mot(root, "petitesirene");
    suppr_mot(root, "flipperledauphin");
    printf("flipperledauphin %d\n",chercher_mot(root,"flipperledauphin"));
   printf("petitesirene %d\n",chercher_mot(root,"petitesirene"));
    return EXIT_SUCCESS;
}
