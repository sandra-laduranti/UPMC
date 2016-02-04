/*
** my_strncat.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:55:48 2012 antoine kepeklian
** Last update Wed Jan 18 17:55:49 2012 antoine kepeklian
*/

#include "lib.h"

char	*my_strncat(char *src, char *dest, int n)
{
  int	i;
  int	j;

  i = my_strlen(src);
  j = n;
  while ((n - j) < n && dest[n - j])
    src[i++] = dest[n - j--];
  src[i] = 0;
  return (src);
}
