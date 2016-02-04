/*
** my_putnbr_base_uns.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:11 2012 antoine kepeklian
** Last update Fri Jan 20 18:01:46 2012 antoine kepeklian
*/

#include "lib.h"

void		my_putnbr_base_uns(unsigned int nbr, char *base)
{
  unsigned int	sup;

  sup = my_strlen(base) - 1;
  if (nbr > sup)
    my_putnbr_base_uns(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
}
