#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "morpion.h"

int	xwrite(int fd, char *buffer, int size)
{
  int	ret;

  ret = write(fd, buffer, size);
  if (ret == -1)
    {
      fprintf(stderr, "Cannot Write\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int     my_putchar(char c)
{
if (xwrite(1, &c, 1))
    {
      fprintf(stderr, "Cannot Write\n");
      exit(EXIT_FAILURE);
    }
 return (EXIT_SUCCESS);
}

int     my_putstr(char *str)
{
  int   x;

  x = 0;
  my_putchar('\n');
  while (str[x] != '\0')
    {
      my_putchar(str[x]);
      x = x + 1;
    }
  return (EXIT_SUCCESS);
}


/* juste de l'affichage, inutile pour le code en soit */
void     aff_kikoo(int player, int **grid, t_game *gaming)
{
  while (42)
    {
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr(" ()_()  ()_()  ()_()  ()_()  ()_()");
      my_putstr(" (*.*)  (*.*)  (*.*)  (*.*)  (*.*)");
      my_putstr(" (> <)  (> <)  (> <)  (> <)  (> <)");
      my_putstr("  ^ ^    ^ ^    ^ ^    ^ ^    ^ ^ ");
      my_putchar('\n');
      affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(200000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  ( *)   ( *)   ( *)   ( *)   ( *)");
      my_putstr(" o( >)  o( >)  o( >)  o( >)  o( >)");
      my_putstr("    ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(200000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr(" ()_()  ()_()  ()_()  ()_()  ()_()");
      my_putstr(" (   )  (   )  (   )  (   )  (   )");
      my_putstr(" ( o )  ( o )  ( o )  ( o )  ( o )");
      my_putstr("  ^ ^    ^ ^    ^ ^    ^ ^    ^ ^  ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(200000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  (* )   (* )   (* )   (* )   (* )");
      my_putstr("  (< )o  (< )o  (< )o  (< )o  (< )o");
      my_putstr("   ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(300000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr(" ()_()  ()_()  ()_()  ()_()  ()_()");
      my_putstr(" (*.*)  (*.*)  (*.*)  (*.*)  (*.*)");
      my_putstr("<(   )><(   )><(   )><(   )><(   )>");
      my_putstr("  ^ ^    ^ ^    ^ ^    ^ ^    ^ ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(400000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr(" ()_()  ()_()  ()_()  ()_()  ()_()");
      my_putstr(" (*.*)  (*.*)  (*.*)  (*.*)  (*.*)");
      my_putstr(" (> <)  (> <)  (> <)  (> <)  (> <)");
      my_putstr("  ^ ^    ^ ^    ^ ^    ^ ^    ^ ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(400000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr(" ()_()  ()_()  ()_()  ()_()  ()_()");
      my_putstr(" (*.*)  (*.*)  (*.*)  (*.*)  (*.*)");
      my_putstr("<(   )><(   )><(   )><(   )><(   )>");
      my_putstr("  ^ ^    ^ ^    ^ ^    ^ ^    ^ ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(200000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  ( *)   ( *)   ( *)   ( *)   ( *)");
      my_putstr(" o( >)  o( >)  o( >)  o( >)  o( >)");
      my_putstr("    ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(300000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  ( o)   ( o)   ( o)   ( o)   ( o)");
      my_putstr("  o( >)  o( >)  o( >)  o( >)  o( >)");
      my_putstr("    ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(300000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  ( *)   ( *)   ( *)   ( *)   ( *)");
      my_putstr(" o( >)  o( >)  o( >)  o( >)  o( >)");
      my_putstr("    ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(300000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  ( o)   ( o)   ( o)   ( o)   ( o)");
      my_putstr("  o( >)  o( >)  o( >)  o( >)  o( >)");
      my_putstr("    ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(200000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr(" ()_()  ()_()  ()_()  ()_()  ()_()");
      my_putstr(" (   )  (   )  (   )  (   )  (   )");
      my_putstr(" ( o )  ( o )  ( o )  ( o )  ( o )");
      my_putstr("  ^ ^    ^ ^    ^ ^    ^ ^    ^ ^  ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(200000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  (* )   (* )   (* )   (* )   (* )");
      my_putstr("  (< )o  (< )o  (< )o  (< )o  (< )o");
      my_putstr("   ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(300000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  (o )   (o )   (o )   (o )   (o )");
      my_putstr(" (< )o  (< )o  (< )o  (< )o  (< )o");
      my_putstr("   ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(300000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  (* )   (* )   (* )   (* )   (* )");
      my_putstr("  (< )o  (< )o  (< )o  (< )o  (< )o");
      my_putstr("   ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(300000);
      system("clear");
      display_grid(grid);
      aff_all_players_point(gaming);
      my_putstr("   ()     ()     ()     ()     ()");
      my_putstr("  (o )   (o )   (o )   (o )   (o )");
      my_putstr(" (< )o  (< )o  (< )o  (< )o  (< )o");
      my_putstr("   ^      ^      ^      ^      ^ ");
      my_putchar('\n');
       affich_player_points(player);
      printf("YOU WIN! \n");
      my_putchar('\r');
      usleep(300000);
      system("clear");
    }
}


