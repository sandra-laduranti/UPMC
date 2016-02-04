#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

/*initialise tous les bits à 0 sur 32 bits */

void	initialiser(t_bignum *num)
{
  int	i;
  int	j;
  int   pos;

  pos = 0;
   for (j=0;j < SIZE; j++)
    {
      for (i=0;i < 32; i++)
	{
	  affecter_bit(num, pos, 0);
	  pos++;
	}  
    }
}
