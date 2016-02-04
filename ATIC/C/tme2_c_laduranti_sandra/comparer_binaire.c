#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

/* récupere la struct ainsi que la position des deux 
 *  j correspond à la valeur
 *  si num1 = num2 return 0
 *  si num1 > num2 return 1
 *  si num1 < num2 return -1 */
int	comparer(t_bignum *num1, t_bignum *num2){
    int i;
    int k;
    int nbr1;
    int nbr2;

    k = SIZE;  
    while (k > 0)
      {
	i = k*SIZE;
	while (i > 0){
	  nbr1 = retourner_bit(num1,i);
	  nbr2 = retourner_bit(num2,i);
	  if (nbr1 == nbr2)
	    i--;
	  if (nbr1 > nbr2)
	    return(1);
	  if (nbr1 < nbr2)
	    return(-1);
	}
	k--;
      }
    return (0);
}
