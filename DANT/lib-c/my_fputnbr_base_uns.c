/*
** my_fputnbr_base_uns.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:07:11 2012 antoine kepeklian
** Last update Fri Jan 20 18:07:12 2012 antoine kepeklian
*/

#include "lib.h"

void		my_fputnbr_base_uns(const int fd, unsigned int nbr, char *base)
{
  unsigned int	sup;

  sup = my_strlen(base) - 1;

  if (nbr > sup)
    my_fputnbr_base_uns(fd, nbr / my_strlen(base), base);
  my_fputchar(fd, base[nbr % my_strlen(base)]);
}

