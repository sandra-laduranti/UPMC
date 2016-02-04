/*
** my_strncpy.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:55:32 2012 antoine kepeklian
** Last update Thu Jan 26 11:05:25 2012 antoine kepeklian
*/

#include "lib.h"

char	*my_strncpy(char *src, char *dest, int n)
{
  int	i;
  int	len;

  i = 0;
  dest = xmalloc((my_strlen(src) + 1) * sizeof(*dest));
  len = my_strlen(src);
  if (n < len)
    len = n;
  while (i < len)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
