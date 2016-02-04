#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

/* verifie que la taille de la grille est conforme
 * si la taille est inférieure à 5 alors on renvoie
 * la valeur d'erreur EXIT_FAILURE*/
int	verif_size()
{
  if (grid_size < 5){
    printf("your value is too small, please enter a size upper or equal than 5\n");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

/* verifie que les coordonées sont bien comprises dans le tableau
* si c'est le cas la valeur not_valid passe à OK et on rentre dans
* la verification de case VIDE, si c'est le cas alors on sort de la
* boucle et on envoie donc les coordonées à complete_box afin de
* remplir le tableau.
* On renvoie la grille modifiée à make_point qui vérifie si une ligne
* a été remplie.*/
int	**empty(int **grid, t_game *gaming)
{
    int x;
    int y;
    int not_valid;
    int free_box;

    not_valid = NOK;
    free_box = NOK;
    while(not_valid == NOK || free_box == NOK){
	printf("please enter coordinate x y\n");
	printf("x:");
	scanf("%d",&x);
	printf("y:");
	scanf("%d",&y);
	if((x > grid_size) || (y > grid_size) || (x <= 0) || (y <= 0)){
	    not_valid = NOK;
	    printf("your value is not correct ");
	}
	else
	  not_valid = OK;
	if (not_valid == OK){
	    if (grid[y-1][x-1] == VIDE)
		free_box = OK;
	    else
		printf("your box is already full ");
	}
    }
    complete_box(gaming,x,y,grid);
    make_point(grid,x-1,y-1,gaming);
    return (grid);
}


/* boucle principale de jeu
 * initialiation de tous les points des joueurs à 0 dans la structure t_game
 * créé la grille avec la valeur grid_size enregistrée dans morpion.h
 * Affiche la grille nouvellement créée
 * boucle tant qu'on ne reçois pas le signal de fin de jeu*/
int	here_we_go(t_game *gaming)
{
    int **grid;
    int	i;
    int j;

    i = 0;
    grid = create_grid();
    display_grid(grid); 
    while (i < 5)
      {
	gaming->tab[i] = 0;
	i++;
      }
    while(finish(gaming, grid) == NOK)
	{
	  if (gaming->computer == OK){
	    if (gaming->turn % 2){
	      printf("tour de l'ordi\n");
	      grid = grid_rand(grid,gaming);
	    }
	    else{
	      printf("au tour de joueur\n");
	      grid = empty(grid, gaming);
	    }
	  }
	  else{
	    grid = empty(grid, gaming);
	  }
	  display_grid(grid);
	}
    for(i =grid_size -1; i >= 0; i--)
      {
	for (j = grid_size - 1;j >=0; j--)
	xfree(grid[i]);
      }
    xfree(grid);
    return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
  t_game *gaming;

  gaming = (t_game *)xmalloc(sizeof(t_game));
  grid_size = 5;
  gaming->computer = NOK;
  options(argc, argv, gaming);
  printf("WELCOME ON MORPION 1.0!\nIf you want options please use ./morpion -h\n");
  verif_struct_game(gaming);
  here_we_go(gaming);
  xfree(gaming);
  return (EXIT_SUCCESS);
}
