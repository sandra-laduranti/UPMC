/*
** my_fputstr.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:06:50 2012 antoine kepeklian
** Last update Fri Jan 20 18:06:52 2012 antoine kepeklian
*/

#include "lib.h"

void	my_fputstr(const int fd, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_fputchar(fd, str[i++]);
}

