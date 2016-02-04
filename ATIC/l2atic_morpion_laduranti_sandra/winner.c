#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

int	verif_horizontal(int **grid, int x, int y, int player)
{
  int	x_init;
  int	y_init;
  int	cpt;

  cpt = 0;
  x_init = x;
  y_init = y;
  while(grid[y][x] == player)
    {
      cpt++;
      if (x < grid_size)
	x++;
      else
      break;
    }
  x = x_init-1;
  y = y_init;
  while(grid[y][x] == player)
    {
      cpt++;
      if (x > 0)
	x--;
      else
	break;
    }
     if (cpt >= 5)
    return (OK);
  else
    return (NOK);
}

int	verif_vertical(int **grid, int x, int y, int player)
{
  int	x_init;
  int	y_init;
  int	cpt;

  cpt = 0;
  x_init = x;
  y_init = y;
  while(grid[y][x] == player)
    {
      cpt++;
      if (y < grid_size-1)
	y++;
      else
	break;
    }
  if (y_init == 0){
    x = x_init;
    y = y_init;
  }
  else{
    x = x_init;
    y = y_init-1;
  }
  while(grid[y][x] == player)
    {
      cpt++;
      if (y > 0)
	y--;
      else
	break;
    }
 if (cpt >= 5)
    return (OK);
  else
    return (NOK);
}

int	verif_diagonal_right(int **grid, int x, int y, int player)
{
  int	x_init;
  int	y_init;
  int	cpt;

  cpt = 0;
  x_init = x;
  y_init = y;
  while(grid[y][x] == player)
    {
      cpt++;
      if (y < grid_size-1){
	y++;
	if (x < grid_size-1)
	  x++;
      }
      else
	break;
    }
 if (x_init == 0 || y_init == grid_size-1 || y_init == 0){
    x = x_init;
    y = y_init;
    cpt--;
  }
 else{
    x = x_init-1;
    y = y_init-1;
  }
  while(grid[y][x] == player)
    {
      cpt++;
      if (y > 0 && x > 0){
	y--;
	x--;
      }
      else
	break;
    }
   if (cpt >= 5)
    return (OK);
  else
    return (NOK);
}

int	verif_diagonal_left(int **grid, int x, int y, int player)
{
 int	x_init;
  int	y_init;
  int	cpt;

  cpt = 0;
  x_init = x;
  y_init = y;
  while(grid[y][x] == player)
    {
      cpt++;
      if (y < 0 && x < grid_size - 1){
	y++;
	x--;
      }
      else
	break;
    }
  if (y_init == 0 || x_init == grid_size-1){
    x = x_init;
    y = y_init;
    cpt--;
  }
  else{
    x = x_init+1;
    y = y_init-1;
  }
  while(grid[y][x] == player)
    {
      cpt++;
      if (y > 0 && x > 0){
	y--;
	x++;
      }
      else
	break;
    }
 if (cpt >= 5)
    return (OK);
  else
    return (NOK);
}

/*appelle toutes les fonctions qui check si une ligne a été remplie
 * et garde dans la structure le point gagné selon le joueur 
 * dans un tableau
 */
void	make_point(int **grid, int x, int y, t_game *gaming)
{
  int player;

   player = (grid[y][x]);
  if (verif_horizontal(grid, x, y, player) == OK && player != 0){
    affich_player_points(player);
    printf("make 1 point in horizontal \n");
    gaming->tab[player]++;
  }
  if (verif_vertical(grid, x, y, player) == OK && player != 0){
    affich_player_points(player);
    printf("make 1 in vertical \n");
    gaming->tab[player]++;
  }
  if (verif_diagonal_right(grid, x, y, player) == OK && player != 0 ){
    affich_player_points(player);
    printf("make 1 in diagonal right \n");
    gaming->tab[player]++;
  }
  if (verif_diagonal_left(grid, x, y, player) == OK &&  player != 0){
    affich_player_points(player);
    printf("make 1 in diagonal left \n");
    gaming->tab[player]++;
  }
}

