/*
** my_memset.c for library in /home/kepekl_b//Documents/lib/my
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Mon Feb 20 15:59:36 2012 antoine kepeklian
** Last update Mon Feb 20 16:24:29 2012 antoine kepeklian
*/

#include "lib.h"

void	*my_memset(void *ptr, char s, int size)
{
  int	i;
  char	*tmp;

  tmp = ptr;
  i = 0;
  while (i < size)
    {
      *tmp = s;
      tmp++;
      i++;
    }
  return (ptr);
}
