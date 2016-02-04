/*
** my_swap.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:55:23 2012 antoine kepeklian
** Last update Wed Jan 18 17:55:25 2012 antoine kepeklian
*/

#include "lib.h"

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (EXIT_SUCCESS);
}
