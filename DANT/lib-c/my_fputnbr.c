/*
** my_fputnbr.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:07:03 2012 antoine kepeklian
** Last update Fri Jan 20 18:07:05 2012 antoine kepeklian
*/

#include "lib.h"

void     my_fputnbr(const int fd, int nbr)
{
  if (nbr < 0)
    {
      my_fputchar(fd, '-');
      nbr = -nbr;
    }
  if (nbr > 9)
    my_fputnbr(fd, nbr / 10);
  my_fputchar(fd, '0' + nbr % 10);
}
