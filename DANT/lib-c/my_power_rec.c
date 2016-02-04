/*
** my_power_rec.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:58:10 2012 antoine kepeklian
** Last update Wed Jan 18 17:58:12 2012 antoine kepeklian
*/

#include "lib.h"

int	my_power_rec(int nbr, int exp)
{
  if (exp < 0)
    return (0);
  if (exp == 0)
    return (1);
  return (my_power_rec(nbr, exp - 1) * nbr);
}
