#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

void	affichage_binaire(t_bignum *num)
{
    int i;
    int j;
    int x;
    unsigned bit;
    unsigned mask;

    j = 0;
    while (num->num[j]){
	x = num->num[j];
	bit = 0;
	mask = 1;
	for (i = 0 ; i < 32 ; ++i)
	{
		bit = (x & mask) >> i ;
		printf("%d", bit) ;
		mask <<= 1 ;
	}
	j++;
	printf("\n");
    }
}
