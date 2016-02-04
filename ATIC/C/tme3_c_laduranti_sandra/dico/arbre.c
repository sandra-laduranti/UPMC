#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dico.h"

noeud   *initialiser()
{
  noeud	*root;
  int	i;

  root = xmalloc(sizeof(noeud));
  root->lettre = '*';
  root->fin_de_mot = OUI;
  root->fils = xmalloc(256*sizeof(noeud));
  for(i = 0; i < 256; i++){
    root->fils[i] = NULL;
  }
  return (root);
}

noeud	*add_noeud(noeud *root, char lettre, int fin_de_mot)
{
  noeud *new_noeud;
  int	i;

  i = 0;
  while (root->fils[i]){
    i++;
  }
  new_noeud = xmalloc(sizeof(noeud));
  root->fils[i] = new_noeud;
  new_noeud->lettre = lettre;
  new_noeud->fin_de_mot = fin_de_mot;
  new_noeud->fils = xmalloc(sizeof(noeud)*256);
  for (i=0; i<256 ;i++)
    new_noeud->fils[i]=NULL;
  return (new_noeud);
}


void	add_word(noeud *root, char *word)
{
  int	i;
  int	j;
  int	size;
  int	find;
  noeud	*tmp;

  i = 0;
  tmp = root;
  size = strlen(word) -1;
  while (word[i] != '\0'){
    j = 0;
    find = 0;
    if (word[i] == tmp->lettre){
      if (i == size)
	tmp->fin_de_mot = OUI;
    }
    else
      while (tmp->fils[j]){
	if (tmp->fils[j]->lettre==word[i]){
	  tmp = tmp->fils[j];
	  find++;
	}
	j++;
      }
    if (find == 0){
      tmp = add_noeud(tmp,word[i],(size==i?OUI:NON));
    }
  i++;
  }
}

int	exist_fils(noeud *s_noeud)
{
  int	i;
  int	j;

  j = 0;
  for(i=0; i<256; i++){
    if (s_noeud->fils[i])
      j++;
  }
  return (j);
}

int	exist_word(noeud *root,char *word)
{
  int	i;
  int	j;
  noeud	*tmp;

  i = 0;
  if (exist_fils(root) == 0){
    printf("le dico est vide\n");
    return (EXIT_FAILURE);
  }
  tmp = root;
  while(word[i] != '\0'){
    j = 0;
    while (tmp->fils[j]){
      if (tmp->fils[j]->lettre == word[i]){
	tmp = tmp->fils[j];
	if (i == strlen(word)-1 && tmp->fin_de_mot == OUI){
	  return (OUI);
	}
      }
      j++;
    }
    i++;
  }
  return (NON);
}


void	aff_noeud(noeud *root)
{
  aff_noeud_rec(root,"");
}

/* gosh du recurcif on a réussiiiii Q_Q */
void	aff_noeud_rec(noeud *noeud, char *str)
{
  char	*word;
  int	i;

  i = 0;
  if (noeud == NULL)
    return;;
  word = xmalloc(sizeof(char)*strlen(str)+1);
  strcpy(word,str);
  word[strlen(str)]=noeud->lettre;
  word[strlen(str)+1]='\0';
  if (noeud->fin_de_mot == OUI)
    printf("%s\n",word);
  while(noeud->fils[i]){
    aff_noeud_rec(noeud->fils[i],word);
    i++;
  }
  free(word);
  return;
}


noeud	*return_letter(noeud *root, char *word)
{
  int	i;
  int	j;
  noeud	*tmp;

  i = 0;
  j = 0;
  tmp = root;
  while(word[i]!='\0'){
    while(j<256 && tmp->fils[j]!=NULL){
      if(word[i]==tmp->fils[j]->lettre){
	tmp=tmp->fils[j];
      }
      j++;
    }
    i++;
    j=0;
  }
  return tmp;
}


int	suppr_word(noeud *racine, char *mot)
{
  int	i;
  int	size;
  int	newsize;
  char	*terme;
  noeud *word;

  size = strlen(mot)-1;
  newsize = size+1;
  if (exist_word(racine,mot) == NON){
    printf("%s  n'existe pas dans le dictionnaire\n", mot);
    return (EXIT_FAILURE);
  }
  word = return_letter(racine, mot);
if (exist_fils(word)){
    word->fin_de_mot = NON;
    printf("%s supprimé\n",mot);
    return (EXIT_SUCCESS);
    };
 
  for (i = 0; i < size; i++)
    {
      terme = xmalloc(sizeof(char)*newsize + 1);
      terme = strncpy(terme,mot,newsize);
      terme[newsize] = '\0';
      word = return_letter(racine, terme);
      printf("word->letter %c %d\n",word->lettre, exist_fils(word));
      if (exist_fils(word) == 0){
	word->fin_de_mot = NON;
	free(word);
      }
      free(terme);
      newsize--;
      }
  return (EXIT_SUCCESS);
}
