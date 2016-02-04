#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

/* creation dynamique de la grille de jeu
 *xmalloc verifie le retour d'erreur de malloc et exit si celui-ci indique
 *un problème d'allocation */
int	**create_grid()
{
    int i;
    int j;
    int **grid = xmalloc(grid_size*sizeof(int*));

  
    for (i = 0; i < grid_size; i++){
      grid[i] = xmalloc(grid_size*sizeof(int));
      for(j = 0; j < grid_size; j++){
	grid[i][j]=VIDE;
	}
    }
    return (grid);
}

/* niveau affichage pour le moment la grille ne gere pas les nombres à partir de 10 
 *pour changer couleur remplacer nombre après [ de 31 à 37*/

void	display_grid(int **grid)
{
    int i;
    int j;

    printf("   ");
    for (i=1; i<= grid_size; i++)
	printf(" %d ",i);
    printf("\n");
    for (i = 0; i < grid_size; i++){
	    printf(" %d ",i+1);
	for(j = 0; j < grid_size; j++){
	  switch (grid[i][j]){
	  case YELLOW :
	      printf("\033[33;01m X \033[00m");
	    break;
	  case PURPLE :
	      printf("\033[35;01m O \033[00m");
	    break;
	  case RED :
	      printf("\033[31;01m & \033[00m");
	    break;
	  case GREEN :
	      printf("\033[32;01m * \033[00m");
	    break;
	  case BLUE :
	      printf("\033[34;01m I \033[00m");
	    break;
	  }
	  if(grid[i][j] == VIDE)
	    printf(" . ");
	}
	printf("\n");
    }
}
