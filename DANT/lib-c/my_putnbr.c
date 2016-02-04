/*
** my_putnbr.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:05 2012 antoine kepeklian
** Last update Wed Jan 18 17:57:07 2012 antoine kepeklian
*/

#include "lib.h"

void     my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  if (nbr > 9)
    my_putnbr(nbr / 10);
  my_putchar('0' + nbr % 10);
}
