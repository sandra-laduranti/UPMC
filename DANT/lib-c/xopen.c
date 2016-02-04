/*
** xopen.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Thu Jan 19 14:55:49 2012 antoine kepeklian
** Last update Thu Jan 26 12:16:36 2012 karim harat
*/

#include "lib.h"

int	xopen(const char *pathname, int flags)
{
  int	fd;

  if ((fd = open(pathname, flags)) == -1)
    {
      my_fprintf(MY_STDERR, "Cannot Open : %s", pathname);
      return (EXIT_FAILURE);
    }
  return (fd);
}
