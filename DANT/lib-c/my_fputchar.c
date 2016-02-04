/*
** my_fputchar.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:07:24 2012 antoine kepeklian
** Last update Fri Jan 20 19:20:17 2012 antoine kepeklian
*/

#include "lib.h"

void	my_fputchar(const int fd, char c)
{
  if (xwrite(fd, &c, 1))
    {
      my_fprintf(MY_STDERR, "Cannot Write\n");
      exit(EXIT_FAILURE);
    }
}
