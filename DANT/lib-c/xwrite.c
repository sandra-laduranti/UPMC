/*
** xwrite.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:54:29 2012 antoine kepeklian
** Last update Fri Jan 20 19:18:47 2012 antoine kepeklian
*/

#include "lib.h"

int	xwrite(int fd, char *buffer, int size)
{
  int	ret;

  ret = write(fd, buffer, size);
  if (ret == -1)
    {
      my_fprintf(MY_STDERR, "Cannot Write\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
