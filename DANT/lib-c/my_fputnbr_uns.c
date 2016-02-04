/*
** my_fputnbr_uns.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:06:58 2012 antoine kepeklian
** Last update Fri Jan 20 18:06:59 2012 antoine kepeklian
*/

#include "lib.h"

void     my_fputnbr_uns(const int fd, unsigned int nbr)
{
  if (nbr > 9)
    my_fputnbr_uns(fd, nbr / 10);
  my_fputchar(fd, '0' + nbr % 10);
}
