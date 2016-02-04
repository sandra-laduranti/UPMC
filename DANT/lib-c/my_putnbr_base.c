/*
** my_putnbr_base.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:21 2012 antoine kepeklian
** Last update Wed Jan 18 17:57:22 2012 antoine kepeklian
*/

#include "lib.h"

void     my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  if (nbr > my_strlen(base) - 1)
    my_putnbr_base(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
}
