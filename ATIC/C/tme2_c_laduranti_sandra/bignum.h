#ifndef __BIGNUM_H__
#define __BIGNUM_H__


#define SIZE 16

typedef struct s_bignum{
unsigned long long num[SIZE];
} t_bignum;

int	retourner_bit(t_bignum *num, int position);
int	xfree(void *ptr);
int	comparer(t_bignum *num1, t_bignum *num2);
int	somme_bit(t_bignum *num1, t_bignum *num2, int position, int retenue);
int	calcul_retenue(t_bignum *num1, t_bignum *num2, int position, int retenue);
int	soustraction_binaire(t_bignum *num1, t_bignum *num2, int position, int retenue);
int	retenue_binaire(t_bignum *num1, t_bignum *num2, int position, int retenue);

void	initialiser(t_bignum *num);
void	test_fonctions(t_bignum *number, t_bignum *number2);
void	affecter_bit(t_bignum *num, int position, int valeur);

void    *xmalloc(unsigned int size);
void	affichage_binaire(t_bignum *num);

t_bignum   *somme(t_bignum *num1, t_bignum *num2);
t_bignum     *soustraction(t_bignum *num1, t_bignum *num2);

#endif
