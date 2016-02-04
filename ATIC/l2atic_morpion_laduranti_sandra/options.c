#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "morpion.h"

/* Option h => help
 *Option g => "grid" défini la taille de la grille
 *Option j => "joueur" défini le nombre de joueurs
 *Option l => "ligne" défini le nombre de fois que 
 *l'on peux utiliser un point
 * ? est la valeur renvoyée par défaut par getopt en
 * cas d'erreur, si une option n'est pas acceptée
 * ou si un argument n'est pas suivi de son argument.
 * la syntaxe de  getopt prends argc, argv et la liste des options
 * possibles, celles prenant un argument en plus suivi de : (ex j: ) */ 
void	options(int argc, char **argv, t_game *gaming)
{
  int	i;
  char	o;

  i = 0;
  while ((o = getopt (argc, argv, "hcl:j:g:")) != EOF){
    switch (o){
    case 'g' :
      i = atoi(optarg);
      if (i < 5)
	grid_size = 5;
      else
	grid_size = i;
      break;
    case 'j' :
      i = atoi(optarg);
      gaming->players = i;
      break;
    case 'l' :
      i = atoi(optarg);
      gaming->util_line = i;
      break;
    case 'c':
      gaming->computer = OK;
      break;
    case 'h' :
      fprintf(stderr,"Usage:morpion[options]\n \
Options: --n correspond à un entier décimal-- \n \
         -gn Définit la taille n de la grille\n \
          par défaut n = 5, la taille ne peut pas être inférieure à 5\n \
         -jn Définit le nombre n de joueurs \n \
          par défaut n = 1, il ne peut pas y avoir plus de 5 joueurs\n \
         -ln Définit le nombre n possible d'utilisations d'une même case \n \
          par défaut n = 1\n \
	 -c= 1 joueur contre une ia\n");
      exit(EXIT_SUCCESS);
    case '?':
      fprintf(stderr, "Ligne de commande incorrecte\npour plus d'informations ./morpion -h\n");
      exit(EXIT_FAILURE); 
    }
  }
}

/* verifie que l'utilisateur a bien rentré des entiers en arguments
 * si jamais il n'as pas rentré d'entier alors la valeur est 0
 * il faut donc la corriger, la fonction vérifie également que
 * les valeurs imposées ne sont pas dépassées */
void	verif_struct_game(t_game *gaming)
{
  if (gaming->players == 0)
    gaming->players = 2;
  if (gaming->players > 5)
    gaming->players = 5;
  if (gaming->util_line == 0)
    gaming->util_line = 1;
  if (gaming->computer == OK)
    gaming->players = 2;
  gaming->turn = 0;
}
