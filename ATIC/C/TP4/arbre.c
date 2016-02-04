#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"

noeud *initialiser()
{
    int i;
    noeud *racine;
    racine=malloc(sizeof(noeud));
    racine->fils=malloc(sizeof(noeud)*256);
    for(i=0;i<256;i++){
        racine->fils[i]=NULL;
    }
    racine->lettre='*';
    racine->fin_de_mot=1;
    return racine;
}

noeud *ajouternoeud(noeud *racine, char lettre, int fin_de_mot){
    int i=0;
    noeud *newNoeud=malloc(sizeof(noeud));
    while(racine->fils[i]!=NULL){
        i++;
    }
    racine->fils[i]=newNoeud;
    newNoeud->lettre=lettre;
    newNoeud->fin_de_mot=fin_de_mot;
    newNoeud->fils=malloc(sizeof(noeud)*256);
    for(i=0;i<256;i++){
        newNoeud->fils[i]=NULL;
    }
    return newNoeud;
}

    void ajouter_mot(noeud *racine, char* mot){
    int i=0;
    int w;
    noeud* souslocean;
    while(mot[i]!='\0'){
        w=0;
        while(racine->fils[w]!=NULL){
            if(racine->fils[w]->lettre==mot[i]){
                if(strlen(mot)==i){
                    racine->fils[w]->fin_de_mot=1;
                }
                break;
            }
            w++;
        }
        if(racine->fils[w]==NULL){
            souslocean=ajouternoeud(racine,mot[i],(strlen(mot)==i?1:0));
            racine=souslocean;
        }
        i++;
    }
}

int chercher_mot(noeud *racine,char *mot){
    int i=0;
    int j=0;
    int tofind=0;
    noeud* tmp;
    tmp=racine;
    while(mot[i]!='\0'){
      while(j<256&&tmp->fils[j]!=NULL){
            if(mot[i]==tmp->fils[j]->lettre){
                tmp=tmp->fils[j];
                tofind++;
            }
            j++;
        }
        i++;
        j=0;
    }
    if(tofind==strlen(mot)){
        return 1;
    }
    return 0;
}

noeud *return_letter(noeud *racine, char *mot)
{
  int i=0;
  int j=0;
    noeud* tmp;

    tmp=racine;
    while(mot[i]!='\0'){
        while(j<256&&tmp->fils[j]!=NULL){
            if(mot[i]==tmp->fils[j]->lettre){
                tmp=tmp->fils[j];
            }
            j++;
        }
        i++;
        j=0;
    }
    return tmp;
}

int	verif_fils(noeud *noeud)
{
  int j;
  int exist;

  exist = 0;
  while(j<256)
    {
      if (noeud->fils)
	exist++;
      j++;
    }
  return (exist);
}

int	suppr_mot(noeud *racine, char *mot)
{
  int	i;
  int size;
  int newsize;
  char	*terme;
  noeud *word;

  size = strlen(mot);
  newsize = size;
  if (chercher_mot(racine,mot) == 0){
    printf("ce mot n'existe pas dans le dictionnaire\n");
    return (EXIT_FAILURE);
  }
  word = return_letter(racine, mot);
  /* if (verif_fils(word)){
    word->fin_de_mot = 0;
    return (EXIT_SUCCESS);
    };*/
  for (i = 0; i < size; i++)
    {
      terme = malloc(sizeof(char)*newsize + 1);
      terme = strncpy(terme,mot,newsize);
      terme[newsize] = '\0';
      word = return_letter(racine, terme);
      free(word->fils);
      free(word);
      free(terme);
      newsize--;
    } 
  return (EXIT_SUCCESS);
}

