/*
** xfree.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:55:13 2012 antoine kepeklian
** Last update Wed Jan 25 17:48:35 2012 antoine kepeklian
*/

#include "lib.h"

int	xfree(void *ptr)
{
  if (!ptr)
    {
      my_fprintf(MY_STDERR, "Cannot free\n");
      return (EXIT_FAILURE);
    }
  else
    free(ptr);
  return (EXIT_SUCCESS);
}
