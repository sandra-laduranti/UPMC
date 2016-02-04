/*
** xread.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:54:41 2012 antoine kepeklian
** Last update Thu Feb 23 10:49:36 2012 antoine kepeklian
*/

#include "lib.h"

int	xread(int fd, char *buffer, int size)
{
  int	ret;

  ret = read(fd, buffer, size);
  if (ret == -1)
    {
      my_fprintf(MY_STDERR, "Cannot read\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
