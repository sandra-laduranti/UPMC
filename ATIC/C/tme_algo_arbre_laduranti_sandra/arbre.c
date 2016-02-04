#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

abr_noeud	*nouveau_noeud(int val)
{
  abr_noeud	*noeud;

  noeud = (abr_noeud *)(xmalloc(sizeof(abr_noeud)));
  noeud->val = val;
  noeud->gauche = NULL; 
  noeud->droite = NULL;
  return (noeud);
}

/* créer un arbre d'un niveau*/
abr_noeud	*exemple()
{
  abr_noeud *root;

  root = nouveau_noeud(5);
  root->gauche = nouveau_noeud(3);
  root->droite = nouveau_noeud(7);
  root->gauche->gauche = nouveau_noeud(2);
  root->gauche->droite = nouveau_noeud(5);
  root->droite->droite = nouveau_noeud(8);
  return (root);
}

int		taille(abr_noeud *root)
{
  if (root == NULL)
    return 0;
  else
    return (taille(root->gauche) + taille(root->droite) + 1);
}

void		aff_prefixe(abr_noeud *root)
{
 printf("%d ",root->val);
  if (root->gauche != NULL){
    aff_prefixe(root->gauche);
  }
  if (root->droite != NULL){
    aff_prefixe(root->droite);
  }
}

void		aff_infixe(abr_noeud *root)
{
  if (root->gauche != NULL){
    aff_infixe(root->gauche);
  }
  printf("%d ",root->val);
  if (root->droite != NULL){
    aff_infixe(root->droite);
  }
}

void		aff_postfixe(abr_noeud *root)
{
  if (root->gauche != NULL){
    aff_postfixe(root->gauche);
  }
  if (root->droite != NULL){
    aff_postfixe(root->droite);
  }
  printf("%d ",root->val);
}

void		min(abr_noeud *root)
{
  if (root->gauche != NULL)
    min(root->gauche);
  if (root->gauche == NULL){
    printf("le min est %d\n", root->val);
  }
}

void		max(abr_noeud *root)
{
  if (root->droite != NULL)
    max(root->droite);
  if (root->droite == NULL){
    printf("le max est %d\n", root->val);
  }
}

abr_noeud	*rechercher(abr_noeud *root, int val)
{
  while (root != NULL && val != root->val){
    if (val < root->val)
      root = root->gauche;
    else
      root = root->droite;
  }
  return (root);
}

int		max_hauteur(int droite, int gauche)
{
  return ((droite>gauche)? droite : gauche);
}

/*considère la racine comme un niveau*/
int		hauteur(abr_noeud *root)
{
  if (root == NULL)
    return 0;
  else
    return (1 + max_hauteur(hauteur(root->droite), hauteur(root->gauche)));
}


/*pas fonctionnel pour le moment*/
abr_noeud	*ajouter(abr_noeud *root, int val)
{
  abr_noeud	*fils;

  if (root == NULL){
    root = nouveau_noeud(val);
  }
  else{
    if (val < root->val){
      ajouter(root->gauche, val);
    }
    else{
      ajouter(root->droite, val);
    }
  }
  return (fils);
}


int		main()
{
  abr_noeud	*root;
  abr_noeud	*fils;

  root = exemple();
  printf("taille = %d\n", taille(root));
  printf("prefixe: ");
  aff_prefixe(root);
  printf("\n infixe: ");
  aff_infixe(root);
  printf("\n postfixe: ");
  aff_postfixe(root);
  printf("\n");
  min(root);
  max(root);
  fils = rechercher(root, 2);
  printf("recherche %d %d\n", 2, fils->val);
  printf("hauteur %d\n", hauteur(root));
  fils = ajouter(root,
  xfree(root);
  return (EXIT_SUCCESS);
}
