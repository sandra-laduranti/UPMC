#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 


/* read sur l'entrée standard N puis N entier
   tri écrit le tab trié sur la sortie standard */
int	main()
{
  int i;
  int swap=1;
  int tmp;
  int n;
  int *tab;
    
    printf("rentrez un nombre\n");
    scanf("%d",&n);
    printf("ma valeur: %d \n", n);
    tab = malloc(sizeof(int)*n);
    for (i = 0; i != n; i++)
      {
	scanf("%d",tab[i]);
      }
    while(swap==1){
	swap=0;
	for(i=0; i<n; i++){
	    if(tab[i+1]<tab[i]){
		tmp=tab[i];
		tab[i]=tab[i+1];
		tab[i+1]=tmp;
		swap =1;
	    }
	}
    }
    for (i = 0; i != n; i++)
      {
	fprintf(0,"%d",tab[i]);
      } 
    free(tab);
    return EXIT_SUCCESS;
}
