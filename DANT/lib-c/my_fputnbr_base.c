/*
** my_fputnbr_base.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:07:17 2012 antoine kepeklian
** Last update Fri Jan 20 18:07:19 2012 antoine kepeklian
*/

#include "lib.h"

void     my_fputnbr_base(const int fd, int nbr, char *base)
{
  if (nbr < 0)
    {
      my_fputchar(fd, '-');
      nbr = -nbr;
    }
  if (nbr > my_strlen(base) - 1)
    my_fputnbr_base(fd, nbr / my_strlen(base), base);
  my_fputchar(fd, base[nbr % my_strlen(base)]);
}
