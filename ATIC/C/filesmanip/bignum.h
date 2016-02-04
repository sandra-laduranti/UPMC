#ifndef __BIGNUM_H__
#define __BIGNUM_H__

#define TAILLE 16

typedef struct {
  int num[TAILLE];
} bignum;

int retourner_bit(bignum num, int position);
void affichage_binaire(bignum num);
void affichage_decimal(bignum num);
bignum entier_aleatoire();
int comparer(bignum n1, bignum n2);
bignum affecter_bit(bignum num, int position, int valeur);
bignum initialiser();
int somme_bit(bignum n1, bignum n2, int position, int retenue);
int calcul_retenue(bignum n1, bignum n2, int position, int retenue);
bignum somme(bignum n1, bignum n2);
bignum multiplication(bignum n1, bignum n2);
int soustraction_binaire(bignum n1, bignum n2, int position, int retenue);
int retenue_binaire(bignum n1, bignum n2, int position, int retenue);
bignum modulo(bignum n1, bignum n2);
bignum division_entiere(bignum n1, bignum n2);
bignum soustraction(bignum n1, bignum n2);

#endif
