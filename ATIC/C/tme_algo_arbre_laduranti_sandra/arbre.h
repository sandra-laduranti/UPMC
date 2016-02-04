#ifndef __ARBRE_H__
#define __ARBRE_H__


typedef struct ABR_Noeud{
  int val;
  struct ABR_Noeud *gauche;
  struct ABR_Noeud *droite;
} abr_noeud;

void	*xmalloc(unsigned int size);
void	xfree(abr_noeud *root);

#endif
