#ifndef __DICO_H__
#define __DICO_H__

#define OUI 1
#define NON -1

typedef struct s_noeud
{
char		lettre;
int		fin_de_mot;
struct s_noeud	**fils;
} noeud;

void    *xmalloc(unsigned int size);
void	add_word(noeud *root, char *word);
void	aff_noeud(noeud *root);
void	aff_noeud_rec(noeud *noeud, char *str);

int     xfree(void *ptr);
int	exist_fils(noeud *s_noeud);
int	exist_word(noeud *root,char *word);

/*int	chercher_mot(noeud *dico, char *mot);
int	nb_mots(noeud *dico);
int     inserer_mots(noeud *dico, char *mot);
int	supprimer_mot(noeud *, char *mot);
void	detruire(struct noeud *dico);*/

noeud	*initialiser();
noeud	*add_noeud(noeud *root, char lettre, int fin_de_mot);
noeud	*return_letter(noeud *root, char *word);
int	suppr_word(noeud *racine, char *mot);

#endif
