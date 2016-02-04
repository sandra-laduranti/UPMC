#ifndef __WHO_H__
#define __WHO_H__

#define SIZE 50

typedef struct	fiche_s
{
  char	*nom;
  int	niveau;
}t_fiche;

void	swap(t_fiche *fiche1, t_fiche *fiche2);
void    *xmalloc(unsigned int size);
int     xfree(void *ptr);

t_fiche	  **create_tab();
t_fiche  *nouvelle_fiche(char *nom, int niv);
t_fiche	**remplir_tab(t_fiche **who,t_fiche *doctor, int i);
void	aff_who(t_fiche **who, int i);


#endif
