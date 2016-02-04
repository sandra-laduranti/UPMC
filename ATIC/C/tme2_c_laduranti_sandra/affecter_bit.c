#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bignum.h"

/*utilise pow pour obtenir la puissance de 2 correspondant à la position du bit a changer
 * utilise floor pour prendre la valeur entière par valeur inférieure
 * cast en int du résultat
 * si jamais on doit passer 0 en 1 on soustrait la puissance correspondant à l'emplacement
 * du bit à remplacer, si jamais on doit passer 1 en 0 on additionne la puissance.
 * si jamais le bit remplacé est égal à valeur dès le départ on ne fait rien. */
void	affecter_bit(t_bignum *num, int position, int valeur)
{
  int  puissance;
  int	x;
  int	y;

  position = (double)position;
  x = position/64;
  y = position%64;
  puissance = (int)(pow(2,y));
  if (retourner_bit(num, position) != valeur){
    if ( valeur == 0)
      num->num[x] = num->num[x] - puissance;
    else
      num->num[x] = num->num[x] + puissance;
  }
}
