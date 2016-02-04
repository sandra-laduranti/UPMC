#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

/*on récupére la somme bit par bit et on l'affecte au fur et à mesure
 * au bignum resultat le bit calculé précedemment, à partir du second
 * tour de boucle on prends en compte les retours de retenue pour 
 * le calcul de la somme,
 * une fois la boucle finie on ajoute le dernier bit en valeur de la derniere
 * retenue */
t_bignum   *somme(t_bignum *num1, t_bignum *num2)
{
  int	i;
  int	somme;
  int	ret;
  t_bignum *res;


  res = (t_bignum *)xmalloc(sizeof(t_bignum));
  ret = 0;
  res->num[0] = 0;
  for (i=0; i < 32; i++)
    {
      somme = somme_bit(num1, num2, i, ret);
      ret = calcul_retenue(num1, num2, i, ret);
      affecter_bit(res, i, somme);
    }
  affecter_bit(res, 32, ret);

  return (res);
}
