#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

int retourner_bit(bignum num, int position)
{
  int position_entier, position_bit, entier, taille_entier_en_bit;
  
  taille_entier_en_bit = 8 * sizeof(int);
  if (position == 0)
    {
      position_entier = 0;
      position_bit = 0;
    } 
  else 
    {
      position_entier = position / taille_entier_en_bit; //position dans le tableau d'entiers
      position_bit = position % taille_entier_en_bit;//position du bit dans l'entier correspondant.
    }
  entier = num.num[position_entier];
  
  return ((entier >> position_bit) & 0x1);  
}

void affichage_binaire(bignum num)
{
  int i, bitsize, intsize;

  intsize = 8 * sizeof(int);
  bitsize = TAILLE * intsize;
  for (i = 0; i < bitsize; i++)
    {
      printf("%d", retourner_bit(num, i));
      if (i != 0 && i % intsize == 0)
	{
	  printf("-");
	}
    }
  printf("\n");
}

/*La fonction affichage decimal se contente d'afficher un à un tous les entiers du tableau bignum. Meme si il n'affiche pas vraiment l'entier en decimal, cette fonction est suffisante pour les tests*/
void affichage_decimal(bignum num)
{
  int i;

  for (i = 0; i < TAILLE; i++)
    {
      printf("%d", num.num[i]);
    }
  printf("\n");
}

int comparer(bignum n1, bignum n2)
{
  int i, bitsize, bit1, bit2;

  bitsize = TAILLE * 8 * sizeof(int);
  for (i = bitsize - 1; i >= 0; i--)
    {
      bit1 = retourner_bit(n1, i);
      bit2 = retourner_bit(n2, i);
      if (bit2 < bit1)
	{
	  return 1;
	}
      else if (bit2 > bit1)
	{
	  return -1;
	}
    }

  return 0;
}

bignum affecter_bit(bignum num, int position, int valeur)
{
  int position_entier, position_bit, entier, taille_entier_en_bit, valeur_existante;
  
  taille_entier_en_bit = 8 * sizeof(int);
  if (position == 0)
    {
      position_entier = 0;
      position_bit = 0;
    } 
  else 
    {
      position_entier = position / taille_entier_en_bit;
      position_bit = position % taille_entier_en_bit;
    }
  
  valeur_existante = num.num[position_entier];
  entier = ~(1 << position_bit);
  valeur_existante &= entier;
  entier = valeur << position_bit;
  valeur_existante |= entier; 
  num.num[position_entier] = valeur_existante;

  return num;
}

bignum initialiser()
{
  bignum num;
  int i, taille_bit;

  taille_bit = TAILLE * 8 * sizeof(int);
  for (i = 0; i < taille_bit; i++)
    {
      num = affecter_bit(num, i, 0);
    }

  return num;
}

int somme_bit(bignum n1, bignum n2, int position, int retenue)
{
  int bit1, bit2, somme;

  bit1 = retourner_bit(n1, position);
  bit2 = retourner_bit(n2, position);
  somme = bit1 + bit2 + retenue;

  return somme % 2; 
}

int calcul_retenue(bignum n1, bignum n2, int position, int retenue)
{
  int bit1, bit2, somme;

  bit1 = retourner_bit(n1, position);
  bit2 = retourner_bit(n2, position);
  somme = bit1 + bit2 + retenue;
  if (somme > 1)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

/*somme bit à bit avec retenues*/
bignum somme(bignum n1, bignum n2)
{
  int i, taille_bit, somme, retenue;
  bignum resultat;

  retenue = 0;
  taille_bit = TAILLE * 8 * sizeof(int);
  for (i = 0; i < taille_bit; i++)
    {
      somme = somme_bit(n1, n2, i, retenue);
      retenue = calcul_retenue(n1, n2, i, retenue);
      resultat = affecter_bit(resultat, i, somme);
    }
  resultat = affecter_bit(resultat, taille_bit, retenue);

  return resultat;
}

bignum decaler_gauche(bignum n1, int decalage)
{
  bignum resultat;
  int i, taille_bit_entier, bit;

  taille_bit_entier = TAILLE * 8 * sizeof(int);
  for (i = taille_bit_entier - 1; i >= 0; i--)
    {
      if (i - decalage < 0)
	{
	  bit = 0;
	}
      else
	{
	  bit = retourner_bit(n1, i - decalage);
	}
      resultat = affecter_bit(resultat, i, bit); 
    }

  return resultat;
}

/* algorithme de multiplication*/
bignum multiplication(bignum n1, bignum n2)
{
  bignum resultat;
  int i, bit, taille_bit;

  resultat = initialiser();
  taille_bit = TAILLE * 8 * sizeof(int);
  for (i = 0; i < taille_bit; i++)
    {
      bit = retourner_bit(n2, i);
      if (bit)
	{
	  // note: decaler de 1 bit vers la gauche est equivalent a multiplier par 2
	  resultat = somme(resultat, decaler_gauche(n1, i));
	}
    }

  return resultat;
}

int soustraction_binaire(bignum n1, bignum n2, int position, int retenue)
{
  int b1, b2, soustraction;

  b1 = retourner_bit(n1, position);
  b2 = retourner_bit(n2, position);
  soustraction = b1 - b2 - retenue;
  if (soustraction < 0)
    {
      return soustraction + 2;
    }
  else
    {
      return soustraction;
    }
}

int retenue_binaire(bignum n1, bignum n2, int position, int retenue)
{
  int b1, b2;

  b1 = retourner_bit(n1, position);
  b2 = retourner_bit(n2, position);

  if (b1 < b2 + retenue)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

/* algorithme de soustraction "comme les soustractions à la main". Attention aux retenues!*/
bignum soustraction(bignum n1, bignum n2)
{
  bignum resultat;
  int taille_bit, i, soustraction, retenue;

  if (comparer(n1,n2) < 0)
    {
      printf("Le nombre donne en premier argument est inferieur au nombre donne en deuxieme argument.\n");
      return;
    }
  retenue = 0;
  taille_bit = TAILLE * 8 * sizeof(int);
  for (i = 0; i < taille_bit; i++)
    {
      soustraction = soustraction_binaire(n1, n2, i, retenue);
      retenue = retenue_binaire(n1, n2, i, retenue);
      resultat = affecter_bit(resultat, i, soustraction);
    }

  return resultat;
}

/*pas besoin de recopier explicitement tous les bits, les bignum etant des struct, ils sont passés par copie*/
bignum copier(bignum num1)
{
  return num1;
}

/* **attention**: solution simple mais TRES inefficace, une autre solution plus compliquee a coder mais tres efficace est possible*/
bignum division_entiere(bignum dividende, bignum diviseur)
{
  bignum resultat, prev, produit, un;

  if (comparer(dividende, diviseur) < 0)
    {
      return initialiser();
    }
  else
    {
      resultat = initialiser();
      resultat.num[0] = 1;
      un = initialiser();
      un.num[0] = 1;
      produit = diviseur;
      while (comparer(dividende, produit) >= 0)
	{
	  prev = copier(resultat);
	  resultat = somme(resultat, un); 
	  produit = multiplication(diviseur, resultat);
	}
      
      return prev;
    }
}

/* n1 mod n2 = n1 -  n2 * (n1 / n2)*/
bignum modulo(bignum n1, bignum n2)
{
  bignum resultat_division, reste;

  resultat_division = division_entiere(n1, n2);
  reste = soustraction(n1, multiplication(resultat_division, n2));

  return reste;
}
