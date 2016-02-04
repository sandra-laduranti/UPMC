/*
** xclose.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Thu Jan 19 15:00:28 2012 antoine kepeklian
** Last update Mon Jan 23 14:44:26 2012 antoine kepeklian
*/

#include "lib.h"

int	xclose(const int fd)
{
  if (close(fd))
    {
      my_fprintf(MY_STDERR, "Cannot close\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
