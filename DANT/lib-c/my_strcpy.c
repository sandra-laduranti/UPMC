/*
** my_strcpy.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:08 2012 antoine kepeklian
** Last update Wed Jan 18 17:56:10 2012 antoine kepeklian
*/

#include "lib.h"

char	*my_strcpy(char *src, char *dest)
{
  int	i;

  i = 0;
  free(dest);
  dest = xmalloc((my_strlen(src) + 1) *sizeof(*src));
  while (i < my_strlen(src))
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
