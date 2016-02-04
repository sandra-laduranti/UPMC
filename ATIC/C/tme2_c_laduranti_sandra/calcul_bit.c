#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

/* on additionne les retours de bit puis on retourne leur somme additionnée à la retenue
 * afin de renvoyer un 0 ou un 1 on renvoie la valeur % 2 (pour la base 2)*/
int	somme_bit(t_bignum *num1, t_bignum *num2, int position, int retenue)
{
  int somme;

  somme = (retourner_bit(num1,position) + retourner_bit(num2,position));

  return ((somme + retenue) % 2);
}

/* si la somme d'un calcul est supérieure à un alors en binaire le nombre obtenue est
 * forcement composé de deux élements (1 + 1 + 0= 10 ou 1 + 1 + 1 = 11) il y a donc
 * une retenue dans le cas où la somme est supérieure à 1 */
int	calcul_retenue(t_bignum *num1, t_bignum *num2, int position, int retenue
)
{
  int somme;

  somme = ((retourner_bit(num1,position) + retourner_bit(num2,position)) + retenue);
  return ((somme > 1)?1:0);
}


int	soustraction_binaire(t_bignum *num1, t_bignum *num2, int position, int retenue)
{
  int	 soustraction;

  if (comparer(num1,num2) < 0)
    return (0);
  soustraction = ((retourner_bit(num1, position) - retourner_bit(num2,position)) - retenue);
  return ((soustraction < 0)?(soustraction+2):soustraction);
}

int	retenue_binaire(t_bignum *num1, t_bignum *num2, int position, int retenue)
{
  return (((retourner_bit(num1,position) < retourner_bit(num2,position) +retenue))?1:0);
}
