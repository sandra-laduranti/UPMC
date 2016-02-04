#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "morpion.h"

int	**grid_rand(int **grid, t_game *gaming)
{
  int	randx;
  int	randy;
  int	ok;
  srand(time(NULL) + clock());

  ok = 1;
  while(ok != 0){
    randx = (int)(rand()%grid_size);
    randy = (int)(rand()%grid_size);
    if (randx < grid_size && randy < grid_size){
      if (grid[randy][randx] == VIDE){
	complete_box(gaming,randx+1,randy+1,grid);
	ok = 0;
      }
    }
  }
  make_point(grid,randx,randy,gaming);
  return (grid);
}
