#include <stdlib.h>
#include <stdio.h>

int	compte(char fic[], int *ligne, int *car, int *mot)
{
  FILE *f;
  int	crs;
  int crs_prev;

  if((f = fopen(fic,"r")) == NULL)
    {
      fprintf(stderr,"Open failed\n");
      return 0;
    }
  while((crs = fgetc(f)) != EOF){
    if (car[0] == 0){
      crs_prev = crs;
      if ((crs >= 33) && (crs <= 126)){
	mot[0]++;
      }
    }
    car[0]++;
    if((crs >= 33) && (crs <= 126) && (crs_prev == ' ')){
      mot[0]++;
    }
   if((crs >= 33) && (crs <= 126) && (crs_prev == '\t')){
      mot[0]++;
    }
    if ((crs >= 33) && (crs <= 126) && (crs_prev == '\n') && (crs != ' ')){
      mot[0]++;
    }
    if(crs == '\n')
      ligne[0]++;
    crs_prev = crs;
  }
  fclose(f);
    return 1;
}

int	main(int argc, char *argv[])
{
  int	i;
  int	j;
  int	arg;
  int	total;
  int	ligne;
  int	car;
  int	mot;

  total = 0;
  ligne = 0;
  j = 0;
  arg = 0;
  if (argc <= 1)
    {
      fprintf(stderr,"error: vous n'avez pas rentré d'arguments\n");
      return (EXIT_FAILURE);
    }
  if (argv[1][0] == '-')
    arg++;
  for (i = arg+1; i < argc; i++)
    {
      ligne = 0;
      car = 0;
      mot = 0;
      if (compte(argv[i],&ligne, &car, &mot) == 0)
	fprintf(stderr,"%s failed\n",argv[i]);
      if (arg == 0){
	printf("%d \t %d \t %d \t %s\n",ligne,mot,car,argv[i]);
      }
      else {
	j = 1;
	while (argv[1][j])
	{
	  if (argv[1][j] == 'l'){
	    printf("%d \t", ligne);
	  }
	  if (argv[1][j] == 'm')
	    printf("%d \t", mot);
	  if (argv[1][j] == 'c')
	    printf("%d \t", car);
	  j++;
	}
      printf("%s\n", argv[i]);
      }
      total = total + ligne;
    }
  printf("%d	total\n",total);
  return (EXIT_SUCCESS);
}
