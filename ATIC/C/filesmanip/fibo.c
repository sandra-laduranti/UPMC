#include <stdio.h>
#include <stdlib.h>
#include "bignum.h"

/* théoriquement bignum est censé marcher mais en
 * vrai marche pas du tout ou alors je fais de la
 * grosse merde avec donc je vais retourner en 
 * unsigned int et me stopper un peu avant que la 
 * fonction ne puisse plus calculer les nombres */
/*int	fibonacci()
{
  bignum    num1;
  bignum    num2;
  bignum    num3;
  int	i;
  
  num1 = initialiser();
  num1.num[0] = 0;
  num2 = initialiser();
  num2.num[0] = 1;
  num3 = initialiser();
  num3.num[0] = 0;
  for (i = 0; i <= 90; i++)
    {
      num3 = somme(num1, num2);
      num1 = num2;
      num2 = num3;
      printf("%d\n",i);
      affichage_decimal(num3);
    }
  printf("\n");
  return EXIT_SUCCESS;
  }*/
  
/* fibonacci:
 * premier terme: f(0) = 0 et f(1) = 1
 * f(x)= f(x-1)+f(x-2) */
int	fibonacci()
{
  unsigned long	num1,num2,num3;
  FILE *f;
  int	i;
  
  num1 = 0;
  num2 = 1;
  num3 = 0;
  if((f = fopen("./Fibo.dat","r+")) == NULL)
    {
      fprintf(stderr,"Open failed\n");
      return EXIT_FAILURE;
    }
  fprintf(f,"0\n"); // on initialise les deux premiers nombres
  fprintf(f,"1\n");
  for (i = 0; i < 90; i++)
    {
      num3 = num1+num2;
      num1 = num2;
      num2 = num3;
      fprintf(f,"%ld\n",num3);
    }
  fclose(f);
  return EXIT_SUCCESS;
}


int	read_fibo(int ligne)
{
  FILE *f;
  int  crs;
  int	i = 0;
  int	endline;

  if((f = fopen("./Fibo.dat","r+")) == NULL)
    {
      fprintf(stderr,"Open failed\n");
      return EXIT_FAILURE;
    }
  while((crs = fgetc(f)) != EOF){
    endline = 0;
    if (crs == '\n'){
      i++;
      endline=1;
    }
    if (i == ligne && endline == 0){
      if (crs != '\n'){
	printf("%c",crs);
      }
    }
    if (i > ligne){
      printf("\n");
      return EXIT_SUCCESS;
    }
  }
  fclose(f);
  return EXIT_FAILURE;
}

int	main()
{
  int	val;

  fibonacci();
  while (1){
    scanf("%d",&val);
  read_fibo(val);
  }
  return EXIT_SUCCESS;
}
