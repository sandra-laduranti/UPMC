#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

/* La case choisie est remplie avec la valeur du joueur actif
 * cette valeur est calculée à partir du nombre de tours et 
 * du nombre de joueurs */
void	complete_box(t_game *gaming, int x, int y, int **grid)
{
  int player;

  player = (gaming->turn % gaming->players) + 1;
  printf("turn %d\n", gaming->turn);
  switch (player){
  case YELLOW :
    grid[y-1][x-1] = YELLOW;
    break;
  case PURPLE :
    grid[y-1][x-1] = PURPLE;
    break;
  case RED :
    grid[y-1][x-1] = RED;
    break;
  case GREEN :
    grid[y-1][x-1] = GREEN;
    break;
  case BLUE :
    grid[y-1][x-1] = BLUE;
    break;
  case 0:
    fprintf(stderr,"GIZMO KAKA!\n");
    exit(EXIT_FAILURE);
  }
  gaming->turn++;
}
