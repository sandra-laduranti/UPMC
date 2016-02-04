#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "who.h"

void	pivot(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}

void	swap(t_fiche *fiche1, t_fiche *fiche2)
{
  t_fiche fiche3;

  fiche3 = *fiche1;
  *fiche1 = *fiche2;
  *fiche2 = fiche3;
}

t_fiche	  **create_tab()
{
  t_fiche **who;

  who = xmalloc(SIZE*sizeof(t_fiche));
  return (who);
}


t_fiche  *nouvelle_fiche(char *nom, int niv)
{
  t_fiche *doctor;

  doctor = xmalloc(sizeof(t_fiche));
  doctor->nom = xmalloc(strlen(nom)*sizeof(char));
  strcpy(doctor->nom,nom);
  doctor->niveau = niv;
  return (doctor);
}

t_fiche	**remplir_tab(t_fiche **who,t_fiche *doctor, int i)
{
  int	j;
  int	find;

  j = 0;
  find = 1;
  who[i] = doctor;
  while(find)
    {
      find = 0;
      j = 0;
      while(j < i)
	{
	  if (who[j]->niveau > who[j+1]->niveau){
	    swap(who[j],who[j+1]);
	    find = 1;
	  }
	  j++;
	}     
    }
  return (who);
}

void	aff_who(t_fiche **who, int i)
{
  int j;

  for (j = 0; j< i; j++)
    {
      printf("nom= %s score= %d\n",who[j]->nom,who[j]->niveau);
    }
  for (j = i-1; j > 0; j--)
    {
      xfree(who[j]->nom);
      xfree(who[j]);
    }
}

/*who => tableau de structure
 *Doctor => une fiche*/
int	main()
{
  int	a;
  int	b;
  int	i;
  char	*name;
  int	score;
  t_fiche **who;
  t_fiche *doctor;

  a = 2;
  b = 3;
  i = 0;
  pivot(&a,&b);
  who = create_tab();
  while(score != -42)
    {
      name = xmalloc(50*sizeof(char));
      printf("rentre ton joueur\n");
      scanf("%s",name);
      printf("rentre son score\n");
      scanf("%d",&score);
      if (score != -42){
	doctor = nouvelle_fiche(name,score);
	who = remplir_tab(who,doctor,i);
      }
      xfree(name);
      i++;
    }
  aff_who(who,i-1);
  xfree(who);
  return (EXIT_SUCCESS);
}
