#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

void		xfree(abr_noeud *root)
{
  free(root->gauche->droite);
  free(root->droite->droite);
  free(root->gauche->gauche);
  free(root->droite);
  free(root->gauche);
  free(root);
}
