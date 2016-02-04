/*
** xmalloc.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:55:00 2012 antoine kepeklian
** Last update Tue Jan 24 17:09:40 2012 antoine kepeklian
*/

#include "lib.h"

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_fprintf(MY_STDERR, "Allocation failure");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

void	*xrealloc(void *ptr, unsigned int size)
{
  if (ptr == NULL)
    ptr = xmalloc(size);
  else
    {
      xfree(ptr);
      ptr = xmalloc(size);
    }
  return (ptr);
}
