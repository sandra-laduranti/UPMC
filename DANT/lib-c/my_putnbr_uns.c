/*
** my_putnbr_uns.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:59 2012 antoine kepeklian
** Last update Wed Jan 18 17:57:00 2012 antoine kepeklian
*/

#include "lib.h"

void     my_putnbr_uns(unsigned int nbr)
{
  if (nbr > 9)
    my_putnbr_uns(nbr / 10);
  my_putchar('0' + nbr % 10);
}
