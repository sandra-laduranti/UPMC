#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

/* la fonction ne demarre que lorsque la grille complète a été remplie
 * elle affiche combien de points chaque joueur a gagné et determine qui
 * a le plus de points
 */

int	aff_all_players_point(t_game *gaming)
{
  int	i;
  int	j;
  int	k;

  i = 1;
  j = 1;
  k = gaming->tab[1];
  while (i <= gaming->players){
    if (i){
      affich_player_points(i);
      printf("win %d points\n", gaming->tab[i]);
    }
    if (gaming->tab[i] > k){
      j = i;
      k = gaming->tab[i];
    }
    i++;
  } 
  k = 1;
  while (k <= gaming->players){
    if(gaming->tab[k] == gaming->tab[j] && k != j){
      return (NUL);
    }
    k++;
  }
  if (gaming->tab[j] == 0)
    return (LOSE);
  return (j);
}

int	finish(t_game *gaming, int **grid)
{
  int	res;

  if (gaming->turn == (grid_size*grid_size))
    {
      res = aff_all_players_point(gaming);
      if (res == NUL){
	printf("\nSorry it was a draw :( \n");
	return (OK);
      }
      else if (res == LOSE){
	printf("\noooooooow nobody wins :( \n");
	return (OK);
      }
      else{
	aff_kikoo(res,grid,gaming);
	return (OK);
      }
    }
return (NOK);
}

void	affich_player_points(int player)
{
 switch (player){
	  case YELLOW :
	    printf("player\033[33;01m X \033[00m");
	    break;
	  case PURPLE :
	    printf("player\033[35;01m O \033[00m");
	    break;
	  case RED :
	    printf("player\033[31;01m & \033[00m");
	    break;
	  case GREEN :
	    printf("player\033[32;01m * \033[00m");
	    break;
	  case BLUE :
	    printf("player\033[34;01m I \033[00m");
	    break;
 }
}
