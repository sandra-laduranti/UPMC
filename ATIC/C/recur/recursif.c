#include  <stdlib.h>
#include <stdio.h>

typedef struct s_list{
  int	val;
  struct s_list *next;
} list;

int	factorielle(int fact)
{
  int	val;

  printf("factorielle: num= %d\n",fact);
  if (fact <= 1){
    printf("factorielle de 1=1\n");
    return (1);
  }
  val = (fact*factorielle(fact-1));
  printf("return factorielle %d = %d\n",fact,val);
  return (val);
}

/* fibonacci:
 * premier terme: f(0) = 0 et f(1) = 1
 * f(x)= f(x-1)+f(x-2) */
int	fibonacci(int x)
{
  int val1;
  int val2;
  int val3;

  printf("fibonacci %d\n",x);
  if (x == 0){
    printf("return 0\n");
    return 0;
  }
  if (x == 1){
    return 1;
  }
  val1 = fibonacci(x-1);
  printf("fibonacci x-1 = %d\n", val1);
  val2 = fibonacci(x-2);
  printf("fibonacci x -2 = %d\n", val2);
  val3 = val1 + val2;
  printf("fibonacci result= %d\n", val3);
  return (val3);
}

/* f(0) = 5 et f(x) = (x + 2) * f(x - 1), le but: f(5) */
int	test_rec(int x)
{
  if (x == 0)
    return (5);
  return ((x + 2)*test_rec(x - 1));
}

list	*creer_liste(int profondeur)
{
  list	*new;

  if (profondeur == 0){
    return (NULL);
  }
  new = malloc(sizeof(list));
  new->next = NULL;
  new->val = profondeur;
  printf("profondeur val = %d\n", new->val);
  new->next = creer_liste(profondeur-1);
  return (new);
}

void	aff_liste(list *elem)
{
  if (elem == NULL)
    return;
  printf("val = %d\n",elem->val);
  aff_liste(elem->next);
}

int	main()
{
  list *new;

 new = creer_liste(5);
 aff_liste(new);
 //  printf("resultat final: %d\n", factorielle(5));
 //printf("resultat final: %d\n", test_rec(5));
 //printf("resultat final: %d\n", fibonacci(5));
 return EXIT_SUCCESS;
}
