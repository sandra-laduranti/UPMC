#ifndef __MORPION_H__
#define __MORPION_H__


#define OK 1
#define FAUX 0
#define VIDE FAUX
#define NOK FAUX

typedef enum resultat {
  WIN = 1,
  LOSE = -1,
  NUL = -2
} RESULTAT;


typedef enum couleur {
    YELLOW = 1,
    PURPLE = 2,
    RED = 3,
    GREEN = 4,
    BLUE = 5
} COULEUR;

/* turn compte le nombre de tours
 *players est le nombre de joueurs
 *util_line est le nombre de fois que l'on peut
 *utiliser un point d'une ligne (au final non implémenté)
 * tab est le tableau des points gagnés par chaque joueur */
typedef struct s_game {
  int	turn;
  int   players;
  int	util_line;
  int	computer;
  int	tab[5];
} t_game;

int   grid_size;

void	make_point(int **grid, int x, int y, t_game *gaming);
void	verif_struct_game(t_game *gaming);
void	display_grid(int **grid);
void	options(int argc, char **argv, t_game *gaming);
void	complete_box(t_game *gaming, int x, int y, int **grid);
void	affich_player_points(int player);
void     aff_kikoo(int player, int **grid, t_game *gaming);
void	*xmalloc(unsigned int size);

int	**create_grid();
int	**empty(int **grid, t_game *gaming);
int	**grid_rand(int **grid, t_game *gaming);

int	aff_all_players_point(t_game *gaming);
int	xwrite(int fd, char *buffer, int size);
int     my_putchar(char c);
int     my_putstr(char *str);
int	finish(t_game *gaming, int **grid);
int	verif_horizontal(int **grid, int x, int y, int player);
int	verif_vertical(int **grid, int x, int y, int player);
int	verif_diagonal_right(int **grid, int x, int y, int player);
int	verif_diagonal_left(int **grid, int x, int y, int player);
int	here_we_go(t_game *gaming);
int	verif_size();
int	xfree(void *ptr);
int     main();


#endif
