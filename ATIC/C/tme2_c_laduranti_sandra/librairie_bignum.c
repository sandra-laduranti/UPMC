#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

int	retourner_bit(t_bignum *num, int position)
{
    int x;
    int y;
    int	tab[1];

    x = position/64;
    y = position%64;
    tab[0] = num->num[x];
    tab[0]=tab[0]>>y;
    return (tab[0] & 0x0001);
}

/* le décalage créée un bignum qu'il va remplir selon le nombre a décaler
 * dans le cas où la position - le décalage serait inférieur à 0 alors on
 * rempli de zero à la position donnée
 * sinon on récupére le bit placé à l'endroit de l'indice i - décalage 
 * et on l'affecte à l'endroit du décalage voulu*/
t_bignum	*decalage(t_bignum *number, int decalage)
{
  t_bignum       *res;
  int		i;
  int		val;

  res = (t_bignum*)xmalloc(sizeof(t_bignum));
  initialiser(res);
  for (i=32; i >= 0; i--){
    if ((i - decalage) < 0){
      val = 0;
    }
    else{
      val = retourner_bit(number, i - decalage);
    }
    affecter_bit(res, i, val);
  }
  return (res);
}


/* Une multiplication par 2 est considérée comme étant un décalage
* de 1 bit vers la gauche
* on calcul donc la somme du resultat calculé au tour de boucle
* précédent et du nombre obtenu par le decalage à gauche*/
t_bignum	*multiplication(t_bignum *num1, t_bignum *num2)
{
 t_bignum *res;
 t_bignum *decal;
  int i;
  int val;

  res = (t_bignum*)xmalloc(sizeof(t_bignum));
  initialiser(res);
  for (i = 0; i < 32; i++)
    {
     val = retourner_bit(num2, i);
      if (val){
	decal = decalage(num1,i);
	res = somme(res, decal);
	xfree(decal);
      }
    }
  return (res);
}
/* la division boucle jusqu'à trouver un nombre dont la multiplication
 * par le diviseur donner un résultat plus grand que le dividende
 * et renvoie le resultat - 1 (vu que la boucle a fait un tour de trop
 * par rapport au resultat attendu */
t_bignum *division(t_bignum *num1, t_bignum *num2)
{
  t_bignum *res;
  t_bignum *produit;
  t_bignum *big_un;
  int i;
  i  = 0;
  res = (t_bignum*)xmalloc(sizeof(t_bignum));
  produit = (t_bignum*)xmalloc(sizeof(t_bignum));
  big_un = (t_bignum*)xmalloc(sizeof(t_bignum));
  if (comparer(num1,num2) < 0)
    {
      initialiser(res);
	return (res);
    }
  else
    {
      initialiser(res);
      affecter_bit(big_un,0,1);
      initialiser(big_un);
      affecter_bit(big_un,0,1);
      produit = num2;
      while (comparer(num1, produit) >= 0 && i<5)
	{
	  res = somme(res, big_un);
	  produit = multiplication(num2, res);
	  i++;
	}
      res = soustraction(res, big_un);
      xfree(produit);
      xfree(big_un);
      return (res);
    }
}

t_bignum	*modulo(t_bignum *num1, t_bignum *num2)
{
  t_bignum	*res;
  t_bignum	*reste;

  res = division(num1, num2);
  affecter_bit(res,32,0);
  reste = soustraction(num1, multiplication(res, num2));
  xfree(res);
  return (reste);
}


void	test_fonctions(t_bignum *number, t_bignum *number2)
{
  int	   position;
  int      res;
  t_bignum *resultat;

  number->num[0] = 6;
  number->num[1] = 0;
  number2->num[0]= 3;
  number2->num[1]= 0;
  
  scanf("%d", &position);
  res = retourner_bit(number, position-1);
  printf("le bit %d est égal à %d\n", position, res);
  affichage_binaire(number);
  affichage_binaire(number2);
  /*printf("on compare num1 et num2%d\n", comparer(number, number2));
  affecter_bit(number, position-1, 0);
  printf("bit affecté en position %d\n", position-1);
  affichage_binaire(number);
  initialiser(number);
  printf("affichage_binaire après initialisation des bits à 0:\n");
  affichage_binaire(number);
  printf("nombre 1 %d nombre 2 %d\n", retourner_bit(number,position), retourner_bit(number2,position));
  printf("somme de 3 bits= %d\n",somme_bit(number,number2,position,0)); 
  printf("calcul retenue= %d\n", calcul_retenue(number, number2, position, 0));
  resultat = somme(number, number2);
  affichage_binaire(resultat);
  xfree(resultat);
  printf("mon res= ");
  resultat = multiplication(number, number2);
  affichage_binaire(resultat);
  printf("resultat\n");
  resultat = division(number, number2);*/
  resultat = modulo(number,number2);
  affichage_binaire(resultat);
  xfree(resultat);
}


/*
 *
*/
int	main()
{
    t_bignum *number;
    t_bignum *number2;

    number = xmalloc(sizeof(t_bignum));
    number2 = xmalloc(sizeof(t_bignum));
    while (42)
      test_fonctions(number,number2);
    xfree(number);
    xfree(number2);
    return (EXIT_SUCCESS);
}
