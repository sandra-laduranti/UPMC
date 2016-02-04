#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

t_bignum     *soustraction(t_bignum *num1, t_bignum *num2)
{
  int		i;
  int		ret;
  int		soustraction;	
  t_bignum      *res;

  res = (t_bignum *)xmalloc(sizeof(t_bignum));

  if (comparer(num1,num2) < 0)
    {
      fprintf(stderr, "[ERROR]: num1 < num2\n");
      return 0;
    }
  ret = 0;
  for (i = 0; i < 32; i++)
    {
      soustraction = soustraction_binaire(num1,num2,i,ret);
      ret = retenue_binaire(num1,num2,i,ret);
      affecter_bit(res,i,soustraction);
    }

  return (res);
}
